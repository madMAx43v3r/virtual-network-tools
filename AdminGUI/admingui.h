/*
 * admingui.h
 *
 *  Created on: Dec 30, 2016
 *      Author: mad
 */

#ifndef INCLUDE_ADMINGUI_H_
#define INCLUDE_ADMINGUI_H_

#include <fstream>

#include <vnl/TcpClient.h>
#include <vnl/ThreadEngine.h>

#include <vnl/TcpClientClient.hxx>
#include <vnl/ProcessClient.hxx>
#include <vnl/tools/AdminGUISupport.hxx>

#include <QApplication>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QSlider>
#include <QTimer>
#include <QTextStream>
#include <QCheckBox>
#include <QIcon>
#include <QTabWidget>
#include <QSplitter>
#include <QTreeWidget>
#include <QListWidget>
#include <QScrollArea>
#include <QStackedWidget>
#include <QTextEdit>
#include <QScrollBar>
#include <QTableWidget>
#include <QHeaderView>
#include <QKeyEvent>
#include <QTreeWidgetItemIterator>


namespace vnl {
namespace tools {

inline std::string subs(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


class AdminGUI : public QWidget, public AdminGUIBase {
	Q_OBJECT
public:
	AdminGUI(vnl::String domain, QApplication* app)
		:	AdminGUIBase(domain, "AdminGUI"), application(app)
	{
		setWindowIcon(QIcon::fromTheme("modem"));
	}
	
	virtual ~AdminGUI() {}
	
protected:
	struct base_t {
		virtual ~base_t() {}
	};
	
	struct module_t : public base_t {
		vnl::Instance instance;
		vnl::info::ObjectInfo info;
		QTreeWidgetItem* tree_item = 0;
		QTextEdit* log_view = 0;
		QTableWidget* config_table = 0;
		bool is_running = true;
	};
	
	struct topic_t : public base_t {
		vnl::Topic topic;
		vnl::Address address;
		QTreeWidgetItem* tree_item = 0;
		QTreeWidget* dump_tree = 0;
		QSplitter* pubsub_widget = 0;
		QTableWidget* publishers = 0;
		QTableWidget* subscribers = 0;
	};
	
	void main() {
		add_input(tunnel);
		
		process_client.set_fail(true);
		process_client.set_timeout(500);
		add_client(process_client);
		
		object_client.set_fail(true);
		object_client.set_timeout(500);
		add_client(object_client);
		
		add_client(tcp_client);
		setup_client();
		
		setWindowTitle(QCoreApplication::applicationName());
		{
			QTimer* timer = new QTimer(this);
			connect(timer, SIGNAL(timeout()), this, SLOT(poll_messages()));
			timer->start(50);
		}
		{
			QTimer* timer = new QTimer(this);
			connect(timer, SIGNAL(timeout()), this, SLOT(update_view()));
			timer->start(update_interval);
		}
		
		QVBoxLayout* vbox = new QVBoxLayout();
		{
			QWidget* widget = new QWidget();
			QHBoxLayout* hbox = new QHBoxLayout();
			
			hbox->addWidget(new QLabel("Target: "));
			QLineEdit* txt_target = new QLineEdit();
			txt_target->setText(QString::fromStdString(target_host.to_string()));
			connect(txt_target, SIGNAL(textEdited(const QString&)), this, SLOT(new_target(const QString&)));
			hbox->addWidget(txt_target);
			
			hbox->addWidget(new QLabel("Port: "));
			QLineEdit* txt_target_port = new QLineEdit();
			txt_target_port->setText(QString::number(target_port));
			txt_target_port->setMaximumWidth(80);
			connect(txt_target_port, SIGNAL(textEdited(const QString&)), this, SLOT(new_target_port(const QString&)));
			hbox->addWidget(txt_target_port);
			
			widget->setMaximumHeight(100);
			widget->setLayout(hbox);
			vbox->addWidget(widget);
		}
		
		QTabWidget* pager = new QTabWidget();
		{
			terminal = new QTextEdit();
			setup_text_edit(terminal);
			pager->addTab(terminal, QIcon::fromTheme("utilities-terminal"), "Terminal");
		}
		{
			QSplitter* splitter = new QSplitter();
			
			module_tree = new QTreeWidget();
			module_tree->setSelectionBehavior(QTreeWidget::SelectItems);
			module_tree->setSelectionMode(QTreeWidget::SingleSelection);
			module_tree->header()->close();
			connect(module_tree, SIGNAL(itemSelectionChanged()), this, SLOT(setCurrentModule()));
			splitter->addWidget(module_tree);
			
			QTabWidget* sub_pager = new QTabWidget();
			
			module_overview = new QTableWidget();
			module_overview->setColumnCount(6);
			module_overview->verticalHeader()->hide();
			module_overview->setSelectionMode(QAbstractItemView::NoSelection);
			module_overview->setHorizontalHeaderLabels(QStringList() << "Domain" << "Topic" << "Sent" << "Received" << "Dropped" << "Cycle Time");
			module_overview->horizontalHeaderItem(0)->setIcon(QIcon::fromTheme("folder"));
			module_overview->horizontalHeaderItem(1)->setIcon(QIcon::fromTheme("text-x-generic"));
			module_overview->horizontalHeaderItem(2)->setIcon(QIcon::fromTheme("go-up"));
			module_overview->horizontalHeaderItem(3)->setIcon(QIcon::fromTheme("go-down"));
			module_overview->horizontalHeaderItem(4)->setIcon(QIcon::fromTheme("edit-delete"));
			module_overview->horizontalHeaderItem(5)->setIcon(QIcon::fromTheme("media-playlist-repeat"));
			sub_pager->addTab(module_overview, QIcon::fromTheme("user-desktop"), "Overview");
			
			module_log_stack = new QStackedWidget();
			sub_pager->addTab(module_log_stack, QIcon::fromTheme("utilities-terminal"), "Log Output");
			
			module_config_stack = new QStackedWidget();
			sub_pager->addTab(module_config_stack, QIcon::fromTheme("document-properties"), "Configuration");
			
			splitter->addWidget(sub_pager);
			QList<int> sizes;
			sizes << 300 << 900;
			splitter->setSizes(sizes);
			
			pager->addTab(splitter, QIcon::fromTheme("computer"), "Modules");
		}
		{
			QSplitter* splitter = new QSplitter();
			
			topic_tree = new QTreeWidget();
			topic_tree->setSelectionBehavior(QTreeWidget::SelectItems);
			topic_tree->setSelectionMode(QTreeWidget::SingleSelection);
			topic_tree->header()->close();
			connect(topic_tree, SIGNAL(itemSelectionChanged()), this, SLOT(setCurrentTopic()));
			splitter->addWidget(topic_tree);
			
			QTabWidget* sub_pager = new QTabWidget();
			
			topic_overview = new QTableWidget();
			topic_overview->setColumnCount(6);
			topic_overview->verticalHeader()->hide();
			topic_overview->setSelectionMode(QAbstractItemView::NoSelection);
			topic_overview->setHorizontalHeaderLabels(QStringList() << "Domain" << "Topic" << "Sent" << "Received" << "Cycle Time" << "Last Seen");
			topic_overview->horizontalHeaderItem(0)->setIcon(QIcon::fromTheme("folder"));
			topic_overview->horizontalHeaderItem(1)->setIcon(QIcon::fromTheme("text-x-generic"));
			topic_overview->horizontalHeaderItem(2)->setIcon(QIcon::fromTheme("go-up"));
			topic_overview->horizontalHeaderItem(3)->setIcon(QIcon::fromTheme("go-down"));
			topic_overview->horizontalHeaderItem(4)->setIcon(QIcon::fromTheme("media-playlist-repeat"));
			topic_overview->horizontalHeaderItem(5)->setIcon(QIcon::fromTheme("user-available"));
			sub_pager->addTab(topic_overview, QIcon::fromTheme("user-desktop"), "Overview");
			
			topic_dump_stack = new QStackedWidget();
			sub_pager->addTab(topic_dump_stack, QIcon::fromTheme("modem"), "Sample View");
			
			topic_pubsub_stack = new QStackedWidget();
			sub_pager->addTab(topic_pubsub_stack, QIcon::fromTheme("network-transmit-receive"), "Publishers / Subscribers");
				
			splitter->addWidget(sub_pager);
			QList<int> sizes;
			sizes << 300 << 900;
			splitter->setSizes(sizes);
			
			pager->addTab(splitter, QIcon::fromTheme("applications-internet"), "Topics");
		}
		vbox->addWidget(pager);
		
		resize(1200, 800);
		setLayout(vbox);
		show();
		application->exec();
		tunnel.close();
		tcp_client.set_fail(true);
		try {
			tcp_client.exit();
		} catch(...) {}
	}
	
	bool handle(vnl::Sample* sample) {
		if(get_channel() == &tunnel) {
			if(do_capture && current_topic && sample->dst_addr == current_topic->address) {
				dump_sample(sample);
			}
			return false;
		}
		return Super::handle(sample);
	}
	
	void handle(const vnl::LogMsg& sample) {
		module_t* module = find_module(sample.src_mac);
		if(module) {
			QString text;
			switch(sample.level) {
			case DEBUG: text += "DEBUG: "; break;
			case INFO: text += "INFO: "; break;
			case WARN: text += "WARN: "; break;
			case ERROR: text += "ERROR: "; break;
			}
			text += sample.msg.to_string().c_str();
			append_html(module->log_view, text);
			
			text = QString("[") + module->instance.topic.to_string().c_str() + "] " + text;
			append_html(terminal, text);
		}
	}
	
	void handle(const vnl::Heartbeat& sample) {
		module_t* module = find_module(sample.src_mac);
		if(module) {
			module->info = sample.info;
			for(auto& entry : sample.info.input_channels) {
				input_channel_map[entry.first] = module;
			}
			for(auto& entry : sample.info.output_channels) {
				output_channel_map[entry.first] = module;
			}
		}
	}
	
	void handle(const vnl::info::RemoteInfo& sample) {
		remote = sample;
		process_client.set_address(remote.domain_name, "Process");
		tcp_client.publish(remote.domain_name, "Process");
		
		vnl::String process_domain;
		try {
			process_domain = process_client.get_private_domain();
		} catch(vnl::Exception& ex) {
			log(ERROR).out << "process.get_private_domain() failed with " << ex.get_type_name() << vnl::endl;
			return;
		}
		
		tcp_client.subscribe(remote.domain_name, "vnl.log");
		tcp_client.subscribe(remote.domain_name, "vnl.heartbeat");
		tcp_client.subscribe(process_domain, "topic_info");
		subscribe(remote.domain_name, "vnl.log");
		subscribe(remote.domain_name, "vnl.heartbeat");
		subscribe(process_domain, "topic_info");
		
		vnl::info::TopicInfoList topic_info;
		try {
			type_info = process_client.get_type_info();
			topic_info = process_client.get_topic_info();
		} catch(vnl::Exception& ex) {
			log(ERROR).out << "handle(const vnl::info::RemoteInfo&): Caught " << ex.get_type_name() << vnl::endl;
			return;
		}
		
		reset_all();
		setWindowTitle(QCoreApplication::applicationName() + " (" + remote.domain_name.to_string().c_str()
				+ " at " + target_host.to_string().c_str() + ":" + QString::number(target_port) + ")");
		
		update_view();
		handle(topic_info);
		log(INFO).out << "Connected to " << remote.domain_name << vnl::endl;
	}
	
	void handle(const vnl::info::TopicInfoList& sample) {
		std::ofstream out(remote.domain_name.to_string() + "_graph.dot", std::ofstream::out | std::ofstream::trunc);
		out << "digraph " << remote.domain_name.to_string() << " {" << std::endl;
		out << "  concentrate = true;" << std::endl << std::endl;
		
		for(topic_t& entry : topics) {
			if(entry.topic.domain != remote.domain_name) {
				out << "  \"" << entry.topic.domain << "." << entry.topic.name << "\" [];" << std::endl;
			}
		}
		out << std::endl;
		for(module_t& entry : modules) {
			out << "  \"" << entry.instance.domain << "." << entry.instance.topic << "\" [label=\"" << entry.instance.topic << "\", style=filled, fillcolor=lightgrey, shape=box];" << std::endl;
		}
		out << std::endl;
		for(module_t& module : modules) {
			for(auto& client : module.info.clients) {
				module_t* source = find_module(client.first);
				if(!source) {
					source = find_module(client.second.proxy);
				}
				if(source) {
					out << "  \"" << source->instance.domain << "." << source->instance.topic << "\" -> \"" << module.instance.domain << "." << module.instance.topic << "\" [color=green3]" << std::endl;
				}
			}
			for(auto& entry : module.info.input_nodes) {
				module_t* source = find_module(entry.first);
				if(source) {
					vnl::String* pin = source->info.output_pins.find(entry.first);
					if(pin) {
						out << "  \"" << module.instance.domain << "." << module.instance.topic << "\" -> \"" << source->instance.domain << "." << source->instance.topic
								<< "\" [color=cyan3, label=\"" << pin->to_string() << "\"" << "]" << std::endl;
					}
				}
			}
		}
		out << std::endl;
		
		int row = 0;
		topic_overview->setRowCount(sample.topics.size());
		for(const vnl::info::TopicInfo& info : sample.topics) {
			topic_t& topic = get_topic(info.topic);
			set_cell_data(topic_overview, row, 0, info.topic.domain.to_string().c_str());
			set_cell_data(topic_overview, row, 1, info.topic.name.to_string().c_str());
			set_cell_data(topic_overview, row, 2, qlonglong(info.send_counter));
			set_cell_data(topic_overview, row, 3, qlonglong(info.receive_counter));
			set_cell_data(topic_overview, row, 4, QString::number(double(info.last_time-info.first_time)/(info.send_counter-1)/1e3, 103, 4) + " ms");
			set_cell_data(topic_overview, row, 5, QString::number((sample.time-info.last_time)/1000000) + " s");
			
			int r = 0;
			for(auto& entry : info.publishers) {
				module_t* module = find_module(entry.first);
				if(module && module->is_running) {
					if(topic.topic.domain != remote.domain_name) {
						out << "  \"" << topic.topic.domain << "." << topic.topic.name << "\" -> \"" << module->instance.domain << "." << module->instance.topic << "\" [color=blue3]" << std::endl;
					}
					set_cell_data(topic.publishers, r, 0, module->instance.domain.to_string().c_str());
					set_cell_data(topic.publishers, r, 1, module->instance.topic.to_string().c_str());
					set_cell_data(topic.publishers, r, 2, qlonglong(entry.second));
					r++;
				}
			}
			topic.publishers->setRowCount(r);
			topic.publishers->sortByColumn(1, Qt::AscendingOrder);
			topic.publishers->sortByColumn(0, Qt::AscendingOrder);
			resize_table(topic.publishers);
			topic.publishers->update();
			
			r = 0;
			for(auto& entry : info.subscribers) {
				module_t* module = find_module(entry.first);
				if(module && module->is_running) {
					if(topic.topic.domain != remote.domain_name) {
						out << "  \"" << module->instance.domain << "." << module->instance.topic << "\" -> \"" << topic.topic.domain << "." << topic.topic.name << "\" [color=red3]" << std::endl;
					}
					set_cell_data(topic.subscribers, r, 0, module->instance.domain.to_string().c_str());
					set_cell_data(topic.subscribers, r, 1, module->instance.topic.to_string().c_str());
					set_cell_data(topic.subscribers, r, 2, qlonglong(entry.second));
					r++;
				}
			}
			topic.subscribers->setRowCount(r);
			topic.subscribers->sortByColumn(1, Qt::AscendingOrder);
			topic.subscribers->sortByColumn(0, Qt::AscendingOrder);
			resize_table(topic.subscribers);
			topic.subscribers->update();
			
			if(sample.time - info.last_time > topic_timeout) {
				topic.tree_item->setIcon(0, QIcon::fromTheme("user-offline"));
			} else {
				topic.tree_item->setIcon(0, QIcon::fromTheme("user-available"));
			}
			
			out << std::endl;
			row++;
		}
		
		topic_overview->sortByColumn(1, Qt::AscendingOrder);
		topic_overview->sortByColumn(0, Qt::AscendingOrder);
		resize_table(topic_overview);
		topic_overview->update();
		
		out << "}" << std::endl;
		out.close();
	}
	
	void dump_sample(vnl::Sample* sample) {
		int64_t now = vnl::currentTimeMicros();
		if(!current_sample_window) {
			current_sample_window = now;
		} else if(now - current_sample_window > sample_window) {
			current_sample_window += sample_window;
			current_sample_count = 0;
		}
		if(current_sample_count >= max_sample_rate * sample_window/1e6) {
			return;
		}
		
		vnl::Page* data = vnl::Page::alloc();
		vnl::io::ByteBuffer buf(data);
		vnl::io::TypeOutput out(&buf);
		vnl::write(out, sample->data);
		out.flush();
		buf.flip();
		
		QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(QString("Sample")));
		item->setIcon(0, QIcon::fromTheme("folder"));
		vnl::io::TypeInput in(&buf);
		dump_sample(in, item);
		current_topic->dump_tree->addTopLevelItem(item);
		current_topic->dump_tree->update();
		data->free_all();
		current_sample_count++;
	}
	
	void dump_sample(vnl::io::TypeInput& in, QTreeWidgetItem* parent, vnl::info::Type* type = 0, vnl::info::TypeName* type_name = 0) {
		int size = 0;
		int id = in.getEntry(size);
		uint32_t hash = 0;
		switch(id) {
		case VNL_IO_BOOL: {
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":    " + (size == VNL_IO_TRUE ? "true" : "false"));
			break;
		}
		case VNL_IO_INTEGER: {
			int64_t value;
			in.readValue(value, id, size);
			if(type && type->is_enum) {
				QString symbol = "0x" + QString::number(value, 16);
				for(const vnl::String& sym : type->symbols) {
					if(vnl::Hash32(sym).value == uint32_t(int32_t(value))) {
						symbol = sym.to_string().c_str();
					}
				}
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":    " + symbol);
			} else {
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":    " + QString::number(value));
			}
			break;
		}
		case VNL_IO_REAL: {
			double value;
			in.readValue(value, id, size);
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":    " + QString::number(value));
			break;
		}
		case VNL_IO_BINARY: {
			in.skip(id, size);
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":    Binary of " + QString::number(size) + " bytes");
			break;
		}
		case VNL_IO_STRING: {
			vnl::String value;
			in.readString(value, size);
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":    \"" + value.to_string().c_str() + "\"");
			break;
		}
		case VNL_IO_ARRAY: {
			vnl::info::Type* type_A = (type_name && type_name->generics.size() >= 1) ? type_info.find(type_name->generics[0]) : 0;
			vnl::info::Type* type_B = (type_name && type_name->generics.size() >= 2) ? type_info.find(type_name->generics[1]) : 0;
			if(type_name && type_name->name == "vnl.Map" && size % 2 == 0) {
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + "  (Map of size " + QString::number(size/2) + ")");
				for(int i = 0; i < size; i += 2) {
					if(i < max_array_size) {
						QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(QString("[") + QString::number(i/2) + "]  Key"));
						dump_sample(in, item, type_A);
						parent->addChild(item);
						item = new QTreeWidgetItem(QStringList(QString("[") + QString::number(i/2) + "]  Value"));
						dump_sample(in, item, type_B);
						parent->addChild(item);
					} else {
						if(i == max_array_size) {
							parent->addChild(new QTreeWidgetItem(QStringList(QString("..."))));
						}
						in.skip();
						in.skip();
					}
				}
			} else {
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + "  (Array of size " + QString::number(size) + ")");
				for(int i = 0; i < size; ++i) {
					if(i < max_array_size) {
						QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(QString("[") + QString::number(i) + "]"));
						dump_sample(in, item, type_A);
						parent->addChild(item);
					} else {
						if(i == max_array_size) {
							parent->addChild(new QTreeWidgetItem(QStringList(QString("..."))));
						}
						in.skip();
					}
				}
			}
			break;
		}
		case VNL_IO_CLASS:
			in.getHash(hash);
			type = type_info.find(hash);
			/* no break */
		case VNL_IO_STRUCT:
			if(type) {
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + "  (" + type->name.to_string().c_str() + ")");
			} else {
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + "  (Class 0x" + QString::number(hash, 16) + ")");
			}
			for(int i = 0; i < size; ++i) {
				uint32_t field_hash;
				in.getHash(field_hash);
				vnl::info::Field* field = 0;
				if(type) {
					for(vnl::info::Field& f : type->fields) {
						if(f.hash == field_hash) {
							field = &f;
							break;
						}
					}
				}
				QString line;
				vnl::info::Type* field_type = 0;
				vnl::info::TypeName* field_type_name = 0;
				if(field) {
					line = field->name.to_string().c_str();
					field_type = type_info.find(field->type.hash);
					field_type_name = &field->type;
				} else {
					line = "0x" + QString::number(field_hash, 16);
				}
				QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(line));
				dump_sample(in, item, field_type, field_type_name);
				parent->addChild(item);
			}
			break;
		default:
			in.skip(id, size);
		}
	}
	
	void setup_client() {
		if(!tcp_client.get_address().is_null()) {
			tcp_client.exit();
		}
		vnl::TcpClient* module = new vnl::TcpClient(vnl::local_domain_name, "TcpClient");
		module->endpoint = target_host;
		module->port = target_port;
		subscribe(module->get_my_private_domain(), "remote_info");
		tcp_client = vnl::spawn(module);
	}
	
signals:
	void setFileName(const QString&);
	
private slots:
	void new_target(const QString& target) {
		target_host = target.toStdString();
		setup_client();
	}
	
	void new_target_port(const QString& port) {
		target_port = port.toInt();
		setup_client();
	}
	
	void setCurrentModule() {
		QList<QTreeWidgetItem*> selection = module_tree->selectedItems();
		if(selection.count() != 1) {
			return;
		}
		QTreeWidgetItem* item = selection.first();
		if(item && item->parent()) {
			QVariant mac = item->data(1, Qt::ItemDataRole::UserRole);
			module_t* module = find_module(mac.toULongLong());
			if(module) {
				module_log_stack->setCurrentWidget(module->log_view);
				module_log_stack->update();
				module_config_stack->setCurrentWidget(module->config_table);
				module_config_stack->update();
				
				if(module->is_running && module->instance.is_alive) {
					object_client.set_address(module->instance.domain, module->instance.src_mac);
					vnl::Map<vnl::String, vnl::String> config_map;
					try {
						config_map = object_client.get_config_map();
						QMap<QString, QString> map;
						for(auto& entry : config_map) {
							map[entry.first.to_string().c_str()] = entry.second.to_string().c_str();
						}
						module->config_table->setRowCount(map.size());
						int row = 0;
						for(auto it = map.begin(); it != map.end(); ++it) {
							set_cell_data(module->config_table, row, 0, it.key());
							set_cell_data(module->config_table, row, 1, it.value());
							row++;
						}
						resize_table(module->config_table);
					} catch (vnl::Exception& ex) {
						log(ERROR).out << "setCurrentModule(): get_config_map() caught " << ex.get_type_name() << vnl::endl;
					}
				}
			}
		}
	}
	
	void setCurrentTopic() {
		QList<QTreeWidgetItem*> selection = topic_tree->selectedItems();
		if(selection.count() != 1) {
			return;
		}
		QTreeWidgetItem* item = selection.first();
		if(item && item->parent()) {
			QVariant domain = item->parent()->data(0, Qt::DisplayRole);
			QVariant name = item->data(0, Qt::DisplayRole);
			vnl::Topic key;
			key.domain = domain.toString().toStdString();
			key.name = name.toString().toStdString();
			topic_t* topic = find_topic(key);
			if(topic) {
				if(current_topic) {
					tcp_client.unsubscribe(current_topic->topic.domain, current_topic->topic.name);
					tunnel.unsubscribe(Address(current_topic->topic.domain, current_topic->topic.name));
				}
				current_topic = topic;
				tcp_client.subscribe(topic->topic.domain, topic->topic.name);
				tunnel.subscribe(Address(topic->topic.domain, topic->topic.name));
				topic_dump_stack->setCurrentWidget(topic->dump_tree);
				topic_dump_stack->update();
				topic_pubsub_stack->setCurrentWidget(topic->pubsub_widget);
				topic_pubsub_stack->update();
			}
		}
	}
	
	void update_view() {
		if(!tcp_client.get_are_connected()) {
			setWindowTitle(QCoreApplication::applicationName());
			return;
		}
		
		for(module_t& module : modules) {
			module.is_running = false;
			module.tree_item->setIcon(0, QIcon::fromTheme("user-offline"));
		}
		
		vnl::Array<vnl::Instance> objects;
		try {
			objects = process_client.get_objects();
		} catch (vnl::Exception& ex) {
			log(ERROR).out << "update_view(): get_objects() caught " << ex.get_type_name() << vnl::endl;
			return;
		}
		
		int row = 0;
		module_overview->setRowCount(objects.size());
		for(vnl::Instance& inst : objects) {
			module_t& module = get_module(inst);
			module.instance = inst;
			module.is_running = true;
			if(module.instance.is_alive) {
				module.tree_item->setIcon(0, QIcon::fromTheme("user-available"));
			} else {
				module.tree_item->setIcon(0, QIcon::fromTheme("user-away"));
			}
			set_cell_data(module_overview, row, 0, module.instance.domain.to_string().c_str());
			set_cell_data(module_overview, row, 1, module.instance.topic.to_string().c_str());
			set_cell_data(module_overview, row, 2, qlonglong(module.info.num_msg_sent));
			set_cell_data(module_overview, row, 3, qlonglong(module.info.num_msg_received));
			set_cell_data(module_overview, row, 4, QString::number(module.info.num_msg_dropped)
				+ " (" + QString::number(100*double(module.info.num_msg_dropped)/(module.info.num_msg_received+1), 103, 2) + "%)");
			set_cell_data(module_overview, row, 5, QString::number(double(module.info.time-module.info.spawn_time)/module.info.num_cycles/1e3, 103, 4) + " ms");
			row++;
		}
		module_overview->sortByColumn(1, Qt::AscendingOrder);
		module_overview->sortByColumn(0, Qt::AscendingOrder);
		resize_table(module_overview);
		module_overview->update();
	}
	
	void poll_messages() {
		poll(0);
		if(!vnl_dorun) {
			this->QWidget::close();
		}
	}
	
	void reset_all() {
		if(current_topic) {
			tunnel.unsubscribe(Address(current_topic->topic.domain, current_topic->topic.name));
			current_topic = 0;
		}
		modules.clear();
		topics.clear();
		input_channel_map.clear();
		output_channel_map.clear();
		terminal->clear();
		module_tree->clear();
		topic_tree->clear();
	}
	
private:
	module_t* find_module(uint64_t src_mac) {
		for(module_t& module : modules) {
			if(module.instance.src_mac == src_mac) {
				return &module;
			}
		}
		module_t** p_module = input_channel_map.find(src_mac);
		if(p_module) {
			return *p_module;
		}
		p_module = output_channel_map.find(src_mac);
		if(p_module) {
			return *p_module;
		}
		return 0;
	}
	
	module_t& get_module(const vnl::Instance& inst) {
		module_t* module = find_module(inst.src_mac);
		if(!module) {
			module = &modules.push_back();
			module->instance = inst;
			
			tcp_client.publish(Address(inst.domain, inst.src_mac));
			
			module->log_view = new QTextEdit();
			setup_text_edit(module->log_view);
			module_log_stack->addWidget(module->log_view);
			
			module->config_table = new QTableWidget();
			module->config_table->setColumnCount(2);
			module->config_table->verticalHeader()->hide();
			module->config_table->setSelectionMode(QAbstractItemView::NoSelection);
			module->config_table->setHorizontalHeaderLabels(QStringList() << "Name" << "Value");
			module->config_table->horizontalHeaderItem(0)->setIcon(QIcon::fromTheme("text-x-generic"));
			module->config_table->horizontalHeaderItem(1)->setIcon(QIcon::fromTheme("text-x-generic"));
			module_config_stack->addWidget(module->config_table);
			
			QString domain = inst.domain.to_string().c_str();
			QTreeWidgetItem* parent = 0;
			{
				QTreeWidgetItemIterator it(module_tree);
				while(*it) {
					if((*it)->parent() == 0 && (*it)->data(0, Qt::DisplayRole) == domain) {
						parent = *it;
					}
					it++;
				}
			}
			if(!parent) {
				parent = new QTreeWidgetItem();
				parent->setData(0, Qt::DisplayRole, domain);
				parent->setIcon(0, QIcon::fromTheme("folder"));
				module_tree->addTopLevelItem(parent);
				parent->setExpanded(true);
			}
			
			module->tree_item = new QTreeWidgetItem();
			module->tree_item->setData(0, Qt::DisplayRole, inst.topic.to_string().c_str());
			module->tree_item->setData(1, Qt::UserRole, QVariant(qulonglong(inst.src_mac.value)));
			parent->addChild(module->tree_item);
			module_tree->sortItems(0, Qt::AscendingOrder);
			module_tree->update();
		}
		return *module;
	}
	
	topic_t* find_topic(const vnl::Topic& top) {
		for(topic_t& topic : topics) {
			if(topic.topic.domain == top.domain && topic.topic.name == top.name) {
				return &topic;
			}
		}
		return 0;
	}
	
	topic_t& get_topic(const vnl::Topic& top) {
		topic_t* found = find_topic(top);
		if(found) {
			return *found;
		}
		
		topic_t& topic = topics.push_back();
		topic.topic = top;
		topic.address = vnl::Address(top.domain, top.name);
		
		topic.dump_tree = new QTreeWidget();
		topic.dump_tree->header()->close();
		topic_dump_stack->addWidget(topic.dump_tree);
		
		topic.pubsub_widget = new QSplitter();
		topic.pubsub_widget->setOrientation(Qt::Vertical);
		
		topic.publishers = new QTableWidget();
		topic.publishers->setColumnCount(3);
		topic.publishers->verticalHeader()->hide();
		topic.publishers->setSelectionMode(QAbstractItemView::NoSelection);
		topic.publishers->setHorizontalHeaderLabels(QStringList() << "Domain" << "Topic" << "Sent");
		topic.publishers->horizontalHeaderItem(0)->setIcon(QIcon::fromTheme("folder"));
		topic.publishers->horizontalHeaderItem(1)->setIcon(QIcon::fromTheme("text-x-generic"));
		topic.publishers->horizontalHeaderItem(2)->setIcon(QIcon::fromTheme("go-up"));
		topic.pubsub_widget->addWidget(topic.publishers);
		
		topic.subscribers = new QTableWidget();
		topic.subscribers->setColumnCount(3);
		topic.subscribers->verticalHeader()->hide();
		topic.subscribers->setSelectionMode(QAbstractItemView::NoSelection);
		topic.subscribers->setHorizontalHeaderLabels(QStringList() << "Domain" << "Topic" << "Received");
		topic.subscribers->horizontalHeaderItem(0)->setIcon(QIcon::fromTheme("folder"));
		topic.subscribers->horizontalHeaderItem(1)->setIcon(QIcon::fromTheme("text-x-generic"));
		topic.subscribers->horizontalHeaderItem(2)->setIcon(QIcon::fromTheme("go-down"));
		topic.pubsub_widget->addWidget(topic.subscribers);
		topic_pubsub_stack->addWidget(topic.pubsub_widget);
		
		QString domain = top.domain.to_string().c_str();
		QTreeWidgetItem* parent = 0;
		{
			QTreeWidgetItemIterator it(topic_tree);
			while(*it) {
				if((*it)->parent() == 0 && (*it)->data(0, Qt::DisplayRole) == domain) {
					parent = *it;
				}
				it++;
			}
		}
		if(!parent) {
			parent = new QTreeWidgetItem();
			parent->setData(0, Qt::DisplayRole, domain);
			parent->setIcon(0, QIcon::fromTheme("folder"));
			topic_tree->addTopLevelItem(parent);
			parent->setExpanded(true);
		}
		
		topic.tree_item = new QTreeWidgetItem();
		topic.tree_item->setData(0, Qt::DisplayRole, top.name.to_string().c_str());
		parent->addChild(topic.tree_item);
		topic_tree->sortItems(0, Qt::AscendingOrder);
		topic_tree->update();
		return topic;
	}
	
	QString time_to_string(int64_t time, int64_t epoch = 0) {
		time -= epoch;
		int64_t sec = 1000*1000;
		int64_t min = 60 * sec;
		return QString().sprintf("%.3ld:%.2ld.%.3ld", time/min, (time/sec) % 60, (time/1000) % 1000);
	}
	
	QTableWidgetItem* set_cell_data(QTableWidget* table, int row, int col, const QVariant& value, Qt::ItemFlags flags = Qt::ItemIsEnabled) {
		QTableWidgetItem* item = table->item(row, col);
		if(!item) {
			item = new QTableWidgetItem();
			table->setItem(row, col, item);
		}
		item->setData(0, value);
		item->setFlags(flags);
		return item;
	}
	
	void resize_table(QTableWidget* table, int padding = 10, int min_width = 80) {
		table->resizeColumnsToContents();
		for(int i = 0; i < table->columnCount(); ++i) {
			int size = table->columnWidth(i) + padding;
			size += padding - (size % padding);
			table->setColumnWidth(i, std::max(size, min_width));
		}
	}
	
	void append_html(QTextEdit* widget, QString text) {
		int old_scrollbar_value = widget->verticalScrollBar()->value();
		bool is_scrolled_down = old_scrollbar_value == widget->verticalScrollBar()->maximum();
		QTextCursor tmp = widget->textCursor();
		setUpdatesEnabled(false);
		widget->moveCursor(QTextCursor::End);
		widget->insertPlainText(text);
		widget->setTextCursor(tmp);
		if(is_scrolled_down) {
			widget->verticalScrollBar()->setValue(widget->verticalScrollBar()->maximum());
		} else {
			widget->verticalScrollBar()->setValue(old_scrollbar_value);
		}
		setUpdatesEnabled(true);
		widget->update();
	}
	
	void setup_text_edit(QTextEdit* widget) {
		widget->setAcceptRichText(false);
		widget->setContextMenuPolicy(Qt::NoContextMenu);
		widget->setReadOnly(true);
		widget->setUndoRedoEnabled(false);
		widget->setLineWrapMode(QTextEdit::NoWrap);
	}
	
private:
	QApplication* application;
	vnl::TcpClientClient tcp_client;
	vnl::ProcessClient process_client;
	vnl::ObjectClient object_client;
	vnl::info::RemoteInfo remote;
	Stream tunnel;
	
	vnl::Map<vnl::Hash32, vnl::info::Type> type_info;
	vnl::Map<vnl::Hash64, module_t*> input_channel_map;
	vnl::Map<vnl::Hash64, module_t*> output_channel_map;
	
	QTextEdit* terminal = 0;
	QTreeWidget* module_tree = 0;
	QTreeWidget* topic_tree = 0;
	
	vnl::Array<module_t> modules;
	QTableWidget* module_overview = 0;
	QStackedWidget* module_log_stack = 0;
	QStackedWidget* module_config_stack = 0;
	
	vnl::Array<topic_t> topics;
	QTableWidget* topic_overview = 0;
	QStackedWidget* topic_pubsub_stack = 0;
	QStackedWidget* topic_dump_stack = 0;
	
	bool do_capture = true;
	topic_t* current_topic = 0;
	int64_t current_sample_window = 0;
	int current_sample_count = 0;
	
};


}	// tools
}	// vnl

#endif /* INCLUDE_ADMINGUI_H_ */

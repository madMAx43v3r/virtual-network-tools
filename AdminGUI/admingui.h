/*
 * admingui.h
 *
 *  Created on: Dec 30, 2016
 *      Author: mad
 */

#ifndef INCLUDE_ADMINGUI_H_
#define INCLUDE_ADMINGUI_H_

#include <vnl/TcpClient.h>
#include <vnl/ThreadEngine.h>

#include <vnl/TcpClientClient.hxx>
#include <vnl/ProcessClient.hxx>
#include <vnl/tools/AdminGUISupport.hxx>
#include <vnl/info/TopicInfoList.hxx>

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
	}
	
	virtual ~AdminGUI() {}
	
protected:
	struct module_t {
		vnl::Instance instance;
		QTreeWidgetItem* tree_item = 0;
		QTextEdit* log_view = 0;
		QTableWidget* config_table = 0;
		bool is_running = true;
	};
	
	struct topic_t {
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
		process_client.set_timeout(200);
		add_client(process_client);
		
		object_client.set_fail(true);
		object_client.set_timeout(200);
		add_client(object_client);
		
		add_client(tcp_client);
		{
			vnl::TcpClient* module = new vnl::TcpClient(vnl::local_domain_name, "TcpClient");
			module->endpoint = target_host;
			module->port = target_port;
			tcp_client = vnl::spawn(module);
		}
		subscribe(tcp_client.get_private_domain(), "remote_info");
		
		setWindowTitle(QCoreApplication::applicationName());
		{
			QTimer* timer = new QTimer(this);
			connect(timer, SIGNAL(timeout()), this, SLOT(poll_messages()));
			timer->start(50);
		}
		{
			QTimer* timer = new QTimer(this);
			connect(timer, SIGNAL(timeout()), this, SLOT(update_view()));
			timer->start(interval);
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
			terminal->setReadOnly(true);
			terminal->setLineWrapMode(QTextEdit::NoWrap);
			pager->addTab(terminal, "Terminal");
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
			
			module_log_stack = new QStackedWidget();
			sub_pager->addTab(module_log_stack, "Log Output");
			
			module_config_stack = new QStackedWidget();
			sub_pager->addTab(module_config_stack, "Configuration");
			
			splitter->addWidget(sub_pager);
			QList<int> sizes;
			sizes << 300 << 900;
			splitter->setSizes(sizes);
			
			pager->addTab(splitter, "Modules");
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
			splitter->addWidget(topic_overview);
			sub_pager->addTab(topic_overview, "Overview");
			
			topic_dump_stack = new QStackedWidget();
			splitter->addWidget(topic_dump_stack);
			sub_pager->addTab(topic_dump_stack, "Sample View");
			
			topic_pubsub_stack = new QStackedWidget();
			splitter->addWidget(topic_pubsub_stack);
			sub_pager->addTab(topic_pubsub_stack, "Publishers / Subscribers");
				
			splitter->addWidget(sub_pager);
			QList<int> sizes;
			sizes << 300 << 900;
			splitter->setSizes(sizes);
			
			pager->addTab(splitter, "Topics");
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
		module_t* module = get_module(sample.src_mac);
		if(module) {
			QString text;
			switch(sample.level) {
			case DEBUG: text += "DEBUG: "; break;
			case INFO: text += "<font color=blue>INFO:</font> "; break;
			case WARN: text += "<font color=orange>WARN:</font> "; break;
			case ERROR: text += "<font color=red>ERROR:</font> "; break;
			}
			text += subs(sample.msg.to_string(), "\n", "<br>").c_str();
			append_html(module->log_view, text);
			
			text = QString("[") + module->instance.topic.to_string().c_str() + "] " + text;
			append_html(terminal, text);
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
		tcp_client.subscribe(process_domain, "topic_info");
		subscribe(remote.domain_name, "vnl.log");
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
		int row = 0;
		topic_overview->setRowCount(sample.topics.size());
		for(const vnl::info::TopicInfo& info : sample.topics) {
			topic_t& topic = get_topic(info.topic);
			set_cell_data(topic_overview, row, 0, info.topic.domain.to_string().c_str());
			set_cell_data(topic_overview, row, 1, info.topic.name.to_string().c_str());
			set_cell_data(topic_overview, row, 2, qlonglong(info.send_counter));
			set_cell_data(topic_overview, row, 3, qlonglong(info.receive_counter));
			set_cell_data(topic_overview, row, 4, QString::number(float(info.last_time-info.first_time)/(info.send_counter-1)/1e3, 103, 4) + " ms");
			set_cell_data(topic_overview, row, 5, QString::number((sample.time-info.last_time)/1000000) + " s");
			
			int r = 0;
			for(auto& entry : info.publishers) {
				module_t* module = get_module(entry.first);
				if(module && module->is_running) {
					set_cell_data(topic.publishers, r, 0, module->instance.domain.to_string().c_str());
					set_cell_data(topic.publishers, r, 1, module->instance.topic.to_string().c_str());
					set_cell_data(topic.publishers, r, 2, qlonglong(entry.second));
					r++;
				}
			}
			topic.publishers->setRowCount(r);
			resize_table(topic.publishers);
			topic.publishers->sortByColumn(1, Qt::AscendingOrder);
			topic.publishers->sortByColumn(0, Qt::AscendingOrder);
			topic.publishers->update();
			
			r = 0;
			for(auto& entry : info.subscribers) {
				module_t* module = get_module(entry.first);
				if(module && module->is_running) {
					set_cell_data(topic.subscribers, r, 0, module->instance.domain.to_string().c_str());
					set_cell_data(topic.subscribers, r, 1, module->instance.topic.to_string().c_str());
					set_cell_data(topic.subscribers, r, 2, qlonglong(entry.second));
					r++;
				}
			}
			topic.subscribers->setRowCount(r);
			resize_table(topic.subscribers);
			topic.subscribers->sortByColumn(1, Qt::AscendingOrder);
			topic.subscribers->sortByColumn(0, Qt::AscendingOrder);
			topic.subscribers->update();
			
			row++;
		}
		resize_table(topic_overview);
		topic_overview->sortByColumn(1, Qt::AscendingOrder);
		topic_overview->sortByColumn(0, Qt::AscendingOrder);
		topic_overview->update();
	}
	
	void dump_sample(vnl::Sample* sample) {
		int64_t now = vnl::currentTimeMicros();
		if(now - last_topic_dump < max_topic_interval) {
			return;
		}
		
		vnl::Page* data = vnl::Page::alloc();
		vnl::io::ByteBuffer buf(data);
		vnl::io::TypeOutput out(&buf);
		vnl::write(out, sample->data);
		out.flush();
		buf.flip();
		
		QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(QString("Sample")));
		vnl::io::TypeInput in(&buf);
		dump_sample(in, item, 0);
		current_topic->dump_tree->addTopLevelItem(item);
		current_topic->dump_tree->update();
		
		data->free_all();
		last_topic_dump = now;
	}
	
	void dump_sample(vnl::io::TypeInput& in, QTreeWidgetItem* parent, vnl::info::Type* type) {
		int size = 0;
		int id = in.getEntry(size);
		uint32_t hash = 0;
		switch(id) {
		case VNL_IO_BOOL: {
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":  " + (size == VNL_IO_TRUE ? "true" : "false"));
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
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":  " + symbol);
			} else {
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":  " + QString::number(value));
			}
			break;
		}
		case VNL_IO_REAL: {
			double value;
			in.readValue(value, id, size);
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":  " + QString::number(value));
			break;
		}
		case VNL_IO_BINARY: {
			in.skip(id, size);
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":  Binary of " + QString::number(size) + " bytes");
			break;
		}
		case VNL_IO_STRING: {
			vnl::String value;
			in.readString(value, size);
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + ":  \"" + value.to_string().c_str() + "\"");
			break;
		}
		case VNL_IO_ARRAY: {
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + "  (Array of size " + QString::number(size) + ")");
			for(int i = 0; i < size; ++i) {
				if(i < max_array_size) {
					QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(QString("[") + QString::number(i) + "]"));
					dump_sample(in, item, 0);
					parent->addChild(item);
				} else {
					if(i == max_array_size) {
						parent->addChild(new QTreeWidgetItem(QStringList(QString("..."))));
					}
					in.skip();
				}
			}
			break;
		}
		case VNL_IO_CLASS:
			in.getHash(hash);
			type = type_info.find(hash);
			/* no break */
		case VNL_IO_STRUCT:
			if(!type) {
				parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + "  (Class 0x" + QString::number(hash, 16) + ")");
				if(hash) {
					in.skip(id, size, hash);
				} else {
					in.skip(id, size);
				}
				return;
			}
			parent->setData(0, Qt::DisplayRole, parent->data(0, Qt::DisplayRole).toString() + "  (" + type->name.to_string().c_str() + ")");
			for(int i = 0; i < size; ++i) {
				uint32_t field_hash;
				in.getHash(field_hash);
				vnl::info::Field* field = 0;
				for(vnl::info::Field& f : type->fields) {
					if(f.hash == field_hash) {
						field = &f;
						break;
					}
				}
				QString line;
				vnl::info::Type* field_type = 0;
				if(field) {
					line = field->name.to_string().c_str();
					field_type = type_info.find(field->type);
				} else {
					line = "0x" + QString::number(field_hash, 16);
				}
				QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(line));
				dump_sample(in, item, field_type);
				parent->addChild(item);
			}
			break;
		default:
			in.skip(id, size);
		}
	}
	
	void setup_client() {
		tcp_client.unsubscribe_all();
		tcp_client.set_endpoint(target_host);
		tcp_client.set_port(target_port);
		tcp_client.reconnect();
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
			module_t* module = get_module(mac.toULongLong());
			if(module) {
				module_log_stack->setCurrentWidget(module->log_view);
				module_log_stack->update();
				module_config_stack->setCurrentWidget(module->config_table);
				module_config_stack->update();
				
				if(module->is_running && module->instance.is_alive) {
					object_client.set_address(module->instance.domain, module->instance.topic);
					vnl::Map<vnl::String, vnl::String> config_map;
					try {
						config_map = object_client.get_config_map();
					} catch (vnl::Exception& ex) {
						log(ERROR).out << "setCurrentModule(): get_config_map() caught " << ex.get_type_name() << vnl::endl;
					}
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
		}
		vnl::Array<vnl::Instance> objects;
		try {
			objects = process_client.get_objects();
		} catch (vnl::Exception& ex) {
			log(ERROR).out << "update_view(): get_objects() caught " << ex.get_type_name() << vnl::endl;
		}
		for(vnl::Instance& inst : objects) {
			module_t& module = get_module(inst);
			module.is_running = true;
		}
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
		terminal->clear();
		module_tree->clear();
		topic_tree->clear();
	}
	
private:
	module_t& get_module(const vnl::Instance& inst) {
		module_t* module = get_module(inst.src_mac);
		if(!module) {
			module = &modules.push_back();
			module->instance = inst;
			
			tcp_client.publish(inst.domain, inst.topic);
			
			module->log_view = new QTextEdit();
			module->log_view->setReadOnly(true);
			module->log_view->setLineWrapMode(QTextEdit::NoWrap);
			module_log_stack->addWidget(module->log_view);
			
			module->config_table = new QTableWidget();
			module->config_table->setColumnCount(3);
			module->config_table->verticalHeader()->hide();
			module->config_table->setSelectionMode(QAbstractItemView::NoSelection);
			module->config_table->setHorizontalHeaderLabels(QStringList() << "Name" << "Value" << "Input");
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
	
	module_t* get_module(uint64_t src_mac) {
		for(module_t& module : modules) {
			if(module.instance.src_mac == src_mac) {
				return &module;
			}
		}
		return 0;
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
		topic.pubsub_widget->addWidget(topic.publishers);
		
		topic.subscribers = new QTableWidget();
		topic.subscribers->setColumnCount(3);
		topic.subscribers->verticalHeader()->hide();
		topic.subscribers->setSelectionMode(QAbstractItemView::NoSelection);
		topic.subscribers->setHorizontalHeaderLabels(QStringList() << "Domain" << "Topic" << "Received");
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
	
	static QTableWidgetItem* set_cell_data(QTableWidget* table, int row, int col, const QVariant& value, Qt::ItemFlags flags = Qt::ItemIsEnabled) {
		QTableWidgetItem* item = table->item(row, col);
		if(!item) {
			item = new QTableWidgetItem();
			table->setItem(row, col, item);
		}
		item->setData(0, value);
		item->setFlags(flags);
		return item;
	}
	
	static void resize_table(QTableWidget* table, int padding = 10, int min_width = 80) {
		table->resizeColumnsToContents();
		for(int i = 0; i < table->columnCount(); ++i) {
			int size = table->columnWidth(i) + padding;
			size += padding - (size % padding);
			table->setColumnWidth(i, std::max(size, min_width));
		}
	}
	
	static void append_html(QTextEdit* widget, QString text) {
		int old_scrollbar_value = widget->verticalScrollBar()->value();
		bool is_scrolled_down = old_scrollbar_value == widget->verticalScrollBar()->maximum();
		QTextCursor tmp = widget->textCursor();
		widget->moveCursor(QTextCursor::End);
		widget->insertHtml(text);
		widget->setTextCursor(tmp);
		if(is_scrolled_down) {
			widget->verticalScrollBar()->setValue(widget->verticalScrollBar()->maximum());
		} else {
			widget->verticalScrollBar()->setValue(old_scrollbar_value);
		}
		widget->update();
	}
	
private:
	QApplication* application;
	vnl::TcpClientClient tcp_client;
	vnl::ProcessClient process_client;
	vnl::ObjectClient object_client;
	vnl::info::RemoteInfo remote;
	Stream tunnel;
	
	vnl::Map<vnl::Hash32, vnl::info::Type> type_info;
	
	QTextEdit* terminal = 0;
	QTreeWidget* module_tree = 0;
	QTreeWidget* topic_tree = 0;
	
	vnl::Array<module_t> modules;
	QStackedWidget* module_log_stack = 0;
	QStackedWidget* module_config_stack = 0;
	
	vnl::Array<topic_t> topics;
	QTableWidget* topic_overview = 0;
	QStackedWidget* topic_pubsub_stack = 0;
	QStackedWidget* topic_dump_stack = 0;
	
	bool do_capture = true;
	topic_t* current_topic = 0;
	int64_t last_topic_dump = 0;
	
};


}	// tools
}	// vnl

#endif /* INCLUDE_ADMINGUI_H_ */

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
		bool running = true;
	};
	
	struct topic_t {
		vnl::Topic topic;
		QScrollArea* dump_widget = 0;
		QTreeWidget* dump_tree = 0;
		QSplitter* pubsub_widget = 0;
		QListWidget* publishers = 0;
		QListWidget* subscribers = 0;
	};
	
	void main() {
		add_client(tcp_client);
		tcp_client = vnl::spawn(new vnl::TcpClient(vnl::local_domain_name, "TcpClient"));
		subscribe(tcp_client.get_private_domain(), "remote_info");
		setup_client();
		
		add_client(process);
		process.set_fail(true);
		process.set_timeout(1000);
		
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
			QSplitter* splitter = new QSplitter();
			{
				QScrollArea* area = new QScrollArea();
				area->setWidgetResizable(true);
				module_tree = new QTreeWidget();
				module_tree->setSelectionBehavior(QTreeWidget::SelectionBehavior::SelectItems);
				module_tree->setSelectionMode(QTreeWidget::SelectionMode::SingleSelection);
				connect(module_tree, SIGNAL(itemSelectionChanged()), this, SLOT(setCurrentModule()));
				area->setWidget(module_tree);
				module_tree->header()->close();
				splitter->addWidget(area);
			}
			
			QTabWidget* sub_pager = new QTabWidget();
			{
				QScrollArea* area = new QScrollArea();
				area->setWidgetResizable(true);
				module_log_stack = new QStackedWidget();
				area->setWidget(module_log_stack);
				sub_pager->addTab(area, "Log Output");
			}
			{
				QScrollArea* area = new QScrollArea();
				area->setWidgetResizable(true);
				module_config_stack = new QStackedWidget();
				area->setWidget(module_config_stack);
				sub_pager->addTab(area, "Configuration");
			}
			splitter->addWidget(sub_pager);
			QList<int> sizes;
			sizes << 300 << 900;
			splitter->setSizes(sizes);
			
			pager->addTab(splitter, "Modules");
		}
		{
			QSplitter* splitter = new QSplitter();
			{
				QScrollArea* area = new QScrollArea();
				area->setWidgetResizable(true);
				topic_tree = new QListWidget();
				connect(topic_tree, SIGNAL(pressed()), this, SLOT(scan()));
				area->setWidget(topic_tree);
				splitter->addWidget(area);
			}
			
			QTabWidget* sub_pager = new QTabWidget();
			{
				topic_dump_stack = new QStackedWidget();
				splitter->addWidget(topic_dump_stack);
				sub_pager->addTab(topic_dump_stack, "Data View");
			}
			{
				topic_pubsub_stack = new QStackedWidget();
				splitter->addWidget(topic_pubsub_stack);
				sub_pager->addTab(topic_pubsub_stack, "Publishers / Subscribers");
			}
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
		tcp_client.exit();
	}
	
	void handle(const vnl::Value& sample, const vnl::Packet& packet) {
		if(!do_capture || packet.dst_addr != current_topic) {
			return;
		}
		int64_t now = vnl::currentTimeMicros();
		if(now - last_topic_update < 500000) {
			return;
		}
		
		vnl::Page* data = vnl::Page::alloc();
		vnl::io::ByteBuffer buf(data);
		vnl::io::TypeOutput out(&buf);
		vnl::write(out, sample);
		out.flush();
		buf.flip();
		
		vnl::io::TypeInput in(&buf);
		read_sample(in);
		data->free_all();
		last_topic_update = now;
	}
	
	void handle(const vnl::LogMsg& sample) {
		module_t* module = get_module(sample.src_mac);
		if(module) {
			QTextCursor tmp = module->log_view->textCursor();
			module->log_view->moveCursor(QTextCursor::End);
			QString text;
			switch(sample.level) {
			case DEBUG: text += "[DEBUG] "; break;
			case INFO: text += "<font color=blue>[INFO]</font> "; break;
			case WARN: text += "<font color=orange>[WARN]</font> "; break;
			case ERROR: text += "<font color=red>[ERROR]</font> "; break;
			}
			text += subs(sample.msg.to_string(), "\n", "<br>").c_str();
			module->log_view->insertHtml(text);
			module->log_view->setTextCursor(tmp);
			module->log_view->update();
		}
	}
	
	void handle(const vnl::info::RemoteInfo& sample) {
		remote = sample;
		tcp_client.subscribe(remote.domain_name, "vnl.log");
		tcp_client.publish(remote.domain_name, "Process");
		process.set_address(remote.domain_name, "Process");
		subscribe(remote.domain_name, "vnl.log");
		
		setWindowTitle(QCoreApplication::applicationName() + " (" + remote.domain_name.to_string().c_str()
				+ " at " + target_host.to_string().c_str() + ":" + QString::number(target_port) + ")");
		
		try {
			type_info = process.get_type_info();
		} catch(vnl::Exception& ex) {
			log(ERROR).out << "process.get_type_info() failed with " << ex.get_type_name() << vnl::endl;
		}
		
		update_view();
		log(INFO).out << "Connected to " << remote.domain_name << vnl::endl;
	}
	
	void read_sample(vnl::io::TypeInput& in) {
		
	}
	
	void setup_client() {
		unsubscribe(remote.domain_name, "vnl.log");
		unsubscribe(current_topic);
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
			}
		}
	}
	
	void update_view() {
		if(process.get_address().is_null()) {
			return;
		}
		for(module_t& module : modules) {
			module.running = false;
		}
		try {
			vnl::Array<vnl::Instance> objects = process.get_objects();
			for(vnl::Instance& inst : objects) {
				module_t& module = get_module(inst);
				module.running = true;
			}
			
			topic_info = process.get_topic_info();
			
			
		} catch (vnl::Exception& ex) {
			log(ERROR).out << "update_view(): Caught " << ex.get_type_name() << vnl::endl;
		}
	}
	
	void poll_messages() {
		poll(0);
		if(!vnl_dorun) {
			this->QWidget::close();
		}
	}
	
private:
	QString time_to_string(int64_t time, int64_t epoch = 0) {
		time -= epoch;
		int64_t sec = 1000*1000;
		int64_t min = 60 * sec;
		return QString().sprintf("%.3ld:%.2ld.%.3ld", time/min, (time/sec) % 60, (time/1000) % 1000);
	}
	
	module_t& get_module(const vnl::Instance& inst) {
		module_t* module = get_module(inst.src_mac);
		if(!module) {
			module = &(*modules.push_back());
			module->instance = inst;
			module->log_view = new QTextEdit();
			module->log_view->setReadOnly(true);
			module->log_view->setLineWrapMode(QTextEdit::NoWrap);
			module_log_stack->addWidget(module->log_view);
			
			QString domain = inst.domain.to_string().c_str();
			QString topic = inst.topic.to_string().c_str();
			QTreeWidgetItem* parent = 0;
			{
				QTreeWidgetItemIterator it(module_tree);
				while(*it) {
					if((*it)->parent() == 0 && (*it)->data(0, Qt::ItemDataRole::DisplayRole) == domain) {
						parent = *it;
					}
					it++;
				}
			}
			if(!parent) {
				parent = new QTreeWidgetItem();
				parent->setData(0, Qt::ItemDataRole::DisplayRole, domain);
				module_tree->addTopLevelItem(parent);
				parent->setExpanded(true);
			}
			
			module->tree_item = new QTreeWidgetItem();
			module->tree_item->setData(0, Qt::ItemDataRole::DisplayRole, topic);
			module->tree_item->setData(1, Qt::ItemDataRole::UserRole, QVariant(qulonglong(inst.src_mac.value)));
			parent->addChild(module->tree_item);
			module_tree->sortItems(0, Qt::SortOrder::AscendingOrder);
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
	
	topic_t& get_topic(const vnl::Topic& top) {
		for(topic_t& topic : topics) {
			if(topic.topic.domain == top.domain && topic.topic.name == top.name) {
				return topic;
			}
		}
		topic_t& topic = *topics.push_back();
		topic.topic = top;
		{
			topic.dump_widget = new QScrollArea();
			topic.dump_tree = new QTreeWidget();
			topic.dump_widget->setWidget(topic.dump_tree);
			topic_dump_stack->addWidget(topic.dump_widget);
		}
		{
			topic.pubsub_widget = new QSplitter();
			topic.pubsub_widget->setOrientation(Qt::Vertical);
			{
				QScrollArea* area = new QScrollArea();
				topic.publishers = new QListWidget();
				area->setWidget(topic.publishers);
				topic.pubsub_widget->addWidget(area);
			}
			{
				QScrollArea* area = new QScrollArea();
				topic.subscribers = new QListWidget();
				area->setWidget(topic.subscribers);
				topic.pubsub_widget->addWidget(area);
			}
			topic_pubsub_stack->addWidget(topic.pubsub_widget);
		}
		return topic;
	}
	
private:
	QApplication* application;
	vnl::TcpClientClient tcp_client;
	vnl::ProcessClient process;
	vnl::info::RemoteInfo remote;
	
	vnl::Map<vnl::Hash32, vnl::info::Type> type_info;
	vnl::Array<vnl::info::TopicInfo> topic_info;
	
	QTreeWidget* module_tree = 0;
	QListWidget* topic_tree = 0;
	
	vnl::List<module_t> modules;
	QStackedWidget* module_log_stack = 0;
	QStackedWidget* module_config_stack = 0;
	
	vnl::List<topic_t> topics;
	QStackedWidget* topic_pubsub_stack = 0;
	QStackedWidget* topic_dump_stack = 0;
	
	bool do_capture = true;
	vnl::Address current_topic;
	int64_t last_topic_update = 0;
	
};


}	// tools
}	// vnl

#endif /* INCLUDE_ADMINGUI_H_ */

#ifndef REPLAYGUI_H
#define REPLAYGUI_H

#include <vnl/tools/ReplayGUISupport.hxx>
#include <vnl/TcpClient.h>
#include <vnl/TcpClientClient.hxx>
#include <vnl/PlayerClient.hxx>
#include <vnl/ThreadEngine.h>
#include <vnl/Player.h>

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


namespace vnl {
namespace tools {

class ReplayGUI : public QWidget, public ReplayGUIBase {
	Q_OBJECT
public:
	ReplayGUI(vnl::String domain, vnl::Pipe* pipe, QApplication* app)
		:	ReplayGUIBase(domain, "ReplayGUI"),
			application(app), pipe(pipe),
			slider(0), do_hold(false), ico_status(0)
	{
	}
	
	virtual ~ReplayGUI() {}
	
protected:
	void main(vnl::Engine* engine) {
		player.set_fail(true);
		player.set_timeout(100);
		player.set_address(vnl::local_domain_name, "Player");
		player.connect(engine);
		
		client.set_fail(true);
		client.set_timeout(100);
		client.connect(engine);
		
		subscribe(vnl::local_domain_name, "PlayerStatus");
		
		{
			QTimer* timer = new QTimer(this);
			connect(timer, SIGNAL(timeout()), this, SLOT(process()));
			timer->start(100);
		}
		{
			QTimer* timer = new QTimer(this);
			connect(timer, SIGNAL(timeout()), this, SLOT(update()));
			timer->start(1000);
		}
		
		QVBoxLayout* vbox = new QVBoxLayout();
		{
			QWidget* widget = new QWidget();
			QHBoxLayout* hbox = new QHBoxLayout();
			
			hbox->addWidget(new QLabel("File: "));
			QLineEdit* txt_file = new QLineEdit();
			txt_file->setReadOnly(true);
			connect(this, SIGNAL(setFileName(const QString&)), txt_file, SLOT(setText(const QString&)));
			hbox->addWidget(txt_file);
			
			QPushButton* btn_open = new QPushButton();
			btn_open->setText("Open");
			btn_open->setIcon(QIcon::fromTheme("document-open"));
			connect(btn_open, SIGNAL(clicked(bool)), this, SLOT(open()));
			hbox->addWidget(btn_open);
			
			widget->setLayout(hbox);
			vbox->addWidget(widget);
		}
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
			
			hbox->addWidget(new QLabel("Status: "));
			ico_status = new QLabel();
			hbox->addWidget(ico_status);
			
			widget->setLayout(hbox);
			vbox->addWidget(widget);
		}
		{
			QWidget* widget = new QWidget();
			QHBoxLayout* hbox = new QHBoxLayout();
			
			hbox->addWidget(new QLabel("Time: "));
			QLineEdit* txt_time = new QLineEdit();
			txt_time->setText("000:00.000");
			txt_time->setReadOnly(true);
			txt_time->setMaximumWidth(100);
			connect(this, SIGNAL(setTime(const QString&)), txt_time, SLOT(setText(const QString&)));
			hbox->addWidget(txt_time);
			
			slider = new QSlider();
			slider->setOrientation(Qt::Horizontal);
			slider->setMinimum(0);
			slider->setMaximum(1000);
			slider->setSingleStep(10);
			slider->setPageStep(100);
			slider->setTickInterval(100);
			slider->setTickPosition(QSlider::TicksBelow);
			slider->setTracking(false);
			connect(slider, SIGNAL(actionTriggered(int)), this, SLOT(seek_to(int)));
			connect(slider, SIGNAL(sliderPressed()), this, SLOT(hold_on()));
			connect(slider, SIGNAL(sliderReleased()), this, SLOT(hold_off()));
			connect(this, SIGNAL(setPosition(int)), slider, SLOT(setValue(int)));
			hbox->addWidget(slider);
			
			QLineEdit* txt_time_end = new QLineEdit();
			txt_time_end->setText("000:00.000");
			txt_time_end->setReadOnly(true);
			txt_time_end->setMaximumWidth(100);
			connect(this, SIGNAL(setTimeEnd(const QString&)), txt_time_end, SLOT(setText(const QString&)));
			hbox->addWidget(txt_time_end);
			
			widget->setLayout(hbox);
			vbox->addWidget(widget);
		}
		{
			QWidget* widget = new QWidget();
			QHBoxLayout* hbox = new QHBoxLayout();
			
			QPushButton* btn_scan = new QPushButton();
			btn_scan->setText("Scan");
			btn_scan->setIcon(QIcon::fromTheme("system-search"));
			connect(btn_scan, SIGNAL(pressed()), this, SLOT(scan()));
			hbox->addWidget(btn_scan);
			
			QPushButton* btn_reset = new QPushButton();
			btn_reset->setText("Reset");
			btn_reset->setIcon(QIcon::fromTheme("media-eject"));
			connect(btn_reset, SIGNAL(pressed()), this, SLOT(reset()));
			hbox->addWidget(btn_reset);
			
			QPushButton* btn_stop = new QPushButton();
			btn_stop->setText("Stop");
			btn_stop->setIcon(QIcon::fromTheme("media-playback-stop"));
			connect(btn_stop, SIGNAL(pressed()), this, SLOT(stop()));
			hbox->addWidget(btn_stop);
			
			QPushButton* btn_play = new QPushButton();
			btn_play->setText("Play");
			btn_play->setIcon(QIcon::fromTheme("media-playback-start"));
			connect(btn_play, SIGNAL(pressed()), this, SLOT(play()));
			hbox->addWidget(btn_play);
			
			QPushButton* btn_pause = new QPushButton();
			btn_pause->setText("Pause");
			btn_pause->setIcon(QIcon::fromTheme("media-playback-pause"));
			connect(btn_pause, SIGNAL(pressed()), this, SLOT(pause()));
			hbox->addWidget(btn_pause);
			
			QCheckBox* chk_autoloop = new QCheckBox();
			chk_autoloop->setText("Loop");
			chk_autoloop->setMaximumWidth(80);
			connect(chk_autoloop, SIGNAL(stateChanged(int)), this, SLOT(set_autoloop(int)));
			hbox->addWidget(chk_autoloop);
			
			widget->setLayout(hbox);
			vbox->addWidget(widget);
		}
		
		setup_client();
		
		resize(800, 100);
		setLayout(vbox);
		show();
		application->exec();
	}
	
	void handle(const vnl::info::PlayerStatus& status) {
		emit setFileName(QString::fromStdString(status.filename.to_string()));
		emit setTime(time_to_string(status.current_time, status.begin_time));
		emit setTimeEnd(time_to_string(status.end_time, status.begin_time));
		if(!do_hold) {
			emit setPosition((1000*(status.current_time-status.begin_time)) / (status.end_time-status.begin_time+1));
		}
		last_status = status;
	}
	
signals:
	void setFileName(const QString&);
	void setTime(const QString&);
	void setTimeEnd(const QString&);
	void setPosition(int);
	
private slots:
	void open() {
		QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"));
		if(file_name.size()) {
			player.open(file_name.toStdString());
		}
	}
	
	void new_target(const QString& target) {
		target_host = target.toStdString();
		setup_client();
	}
	
	void new_target_port(const QString& port) {
		target_port = port.toInt();
		setup_client();
	}
	
	void scan() {
		player.scan();
	}
	
	void reset() {
		player.reset();
	}
	
	void stop() {
		player.stop();
	}
	
	void play() {
		player.play();
	}
	
	void pause() {
		player.pause();
	}
	
	void seek_to(int action) {
		float pos = slider->sliderPosition()/1000.;
		log(INFO).out << "Seeking to " << pos << "% ..." << vnl::endl;
		player.seek_rel(pos);
		std::cout << "FINISHED" << std::endl;
	}
	
	void set_autoloop(int state) {
		player.set_autoloop(state == Qt::Checked);
	}
	
	void hold_on() {
		do_hold = true;
	}
	
	void hold_off() {
		do_hold = false;
	}
	
	void set_client_status(const QString& name) {
		ico_status->setPixmap(QPixmap(QIcon::fromTheme(name).pixmap(32, 32)));
	}
	
	void process() {
		poll(0);
	}
	
	void update() {
		bool online = false;
		client.get_are_connected(online);
		if(online) {
			set_client_status("user-available");
		} else {
			set_client_status("user-offline");
		}
	}
	
private:
	QString time_to_string(int64_t time, int64_t epoch = 0) {
		time -= epoch;
		int64_t sec = 1000*1000;
		int64_t min = 60 * sec;
		return QString().sprintf("%.3u:%.2u.%.3u", time/min, (time/sec) % 60, (time/1000) % 1000);
	}
	
	void setup_client() {
		set_client_status("user-offline");
		if(!client.get_address().is_null()) {
			client.exit();
		}
		vnl::TcpClient* module = new vnl::TcpClient(target_host, target_port);
		module->attach(pipe);
		client = vnl::spawn(module);
	}
	
private:
	QApplication* application;
	vnl::info::PlayerStatus last_status;
	PlayerClient player;
	vnl::TcpClientClient client;
	vnl::Pipe* pipe;
	
	QLabel* ico_status;
	QSlider* slider;
	bool do_hold;
	
};


}	// tools
}	// vnl

#endif // REPLAYGUI_H
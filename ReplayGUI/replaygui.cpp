
#include <vnl/TcpServer.h>
#include <vnl/Terminal.h>

#include <signal.h>
#include "replaygui.h"


int main(int argc, char** argv) {
	
	QApplication app(argc, argv);
	QCoreApplication::setApplicationName("ReplayGUI (port: 4444)");
	
	vnl::Layer layer("ReplayGUI");
	
	{
		vnl::Player* module = new vnl::Player(vnl::local_domain_name, "Player");
		module->vnl_max_num_pending = 1000;
		module->interval = 100000;
		vnl::spawn(module);
	}
	{
		vnl::TcpServer* module = new vnl::TcpServer("TcpServer", 4444);
		vnl::spawn(module);
	}
	
	vnl::spawn(new vnl::Terminal());
	
	vnl::tools::ReplayGUI* module = new vnl::tools::ReplayGUI(vnl::local_domain_name, &app);
	vnl::run(module);
	
	::kill(0, SIGINT);
	
	return 0;
}

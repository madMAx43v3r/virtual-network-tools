
#include "replaygui.h"


int main(int argc, char** argv) {
	
	QApplication app(argc, argv);
	
	vnl::Layer layer("ReplayGUI");
	
	vnl::Pipe pipe;
	
	{
		vnl::Player* module = new vnl::Player(vnl::local_domain_name, &pipe);
		module->interval = 100000;
		vnl::spawn(module);
	}
	
	vnl::tools::ReplayGUI* module = new vnl::tools::ReplayGUI(vnl::local_domain_name, &pipe, &app);
	vnl::run(module);
	
	layer.close();
	
	return 0;
}

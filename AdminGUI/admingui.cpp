/*
 * admingui.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: mad
 */

#include <vnl/Layer.h>

#include <signal.h>
#include "admingui.h"


int main(int argc, char** argv) {
	
	QApplication app(argc, argv);
	QCoreApplication::setApplicationName("AdminGUI");
	
	vnl::Layer layer("AdminGUI");
	
	vnl::tools::AdminGUI* module = new vnl::tools::AdminGUI(vnl::local_domain_name, &app);
	vnl::run(module);
	
	::kill(0, SIGINT);
	
	return 0;
}



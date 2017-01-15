/*
 * crc64.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: mwittal
 */

#include <vnl/Util.h>

int main(int argc, char** argv) {
	
	if(argc < 2) {
		std::cout << "Usage: crc64 string" << std::endl;
		return 0;
	}
	
	std::cout << std::hex << vnl::hash64(argv[1]) << std::endl;
	
}

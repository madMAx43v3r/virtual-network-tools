/*
 * crc64.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: mwittal
 */

#include <vnl/Util.h>

int main(int argc, char** argv) {
	
	std::cout << vnl::hash64(argv[1]) << std::endl;
	std::cout << std::hex << vnl::hash64(argv[1]) << std::endl;
	
}

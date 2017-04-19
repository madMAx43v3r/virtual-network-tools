/*
 * vnlrec2json.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: mad
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include <vnl/io.h>
#include <vnl/Layer.h>
#include <vnl/RecordValue.hxx>
#include <vnl/RecordHeader.hxx>
#include <vnl/RecordTypeInfo.hxx>
#include <vnl/RecordConfig.hxx>


vnl::Map<vnl::Hash32, vnl::info::Type>* type_info = 0;
vnl::Map<vnl::String, vnl::String>* config = 0;

void dump_sample(vnl::io::TypeInput& in, vnl::info::Type* type = 0, vnl::info::TypeName* type_name = 0) {
	int size = 0;
	int id = in.getEntry(size);
	uint32_t hash = 0;
	switch(id) {
	case VNL_IO_BOOL: {
		std::cout << (size == VNL_IO_TRUE ? "true" : "false");
		break;
	}
	case VNL_IO_INTEGER: {
		int64_t value;
		in.readValue(value, id, size);
		if(type && type->is_enum) {
			vnl::String symbol;
			symbol << vnl::hex(value);
			for(const vnl::String& sym : type->symbols) {
				if(vnl::Hash32(sym).value == uint32_t(int32_t(value))) {
					symbol = sym;
				}
			}
			std::cout << "\"" << symbol << "\"";
		} else {
			std::cout << value;
		}
		break;
	}
	case VNL_IO_REAL: {
		double value;
		in.readValue(value, id, size);
		std::cout << std::setprecision(12) << value;
		break;
	}
	case VNL_IO_BINARY: {
		in.skip(id, size);
		std::cout << "\"TODO: print binary as hex\"";
		break;
	}
	case VNL_IO_STRING: {
		vnl::String value;
		in.readString(value, size);
		std::cout << vnl::to_string(value).to_string();
		break;
	}
	case VNL_IO_ARRAY: {
		vnl::info::Type* type_A = (type_name && type_name->generics.size() >= 1) ? type_info->find(type_name->generics[0]) : 0;
		std::cout << "[";
		for(int i = 0; i < size; ++i) {
			dump_sample(in, type_A);
			if(i < size-1) {
				std::cout << ", ";
			}
		}
		std::cout << "]";
		break;
	}
	case VNL_IO_MAP: {
		vnl::info::Type* type_A = (type_name && type_name->generics.size() >= 1) ? type_info->find(type_name->generics[0]) : 0;
		vnl::info::Type* type_B = (type_name && type_name->generics.size() >= 2) ? type_info->find(type_name->generics[1]) : 0;
		std::cout << "[";
		for(int i = 0; i < size; ++i) {
			std::cout << "{\"key\": ";
			dump_sample(in, type_A);
			std::cout << ", \"value\": ";
			dump_sample(in, type_B);
			std::cout << "}";
			if(i < size-1) {
				std::cout << ", ";
			}
		}
		std::cout << "]";
		break;
	}
	case VNL_IO_CLASS:
		in.getHash(hash);
		type = type_info->find(hash);
		/* no break */
	case VNL_IO_STRUCT:
		std::cout << "{\"vni_type\" : \"";
		if(type) {
			std::cout << type->name.to_string();
		} else {
			std::cout << (vnl::String() << vnl::hex(hash)).to_string();
		}
		std::cout << "\", ";
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
			vnl::info::Type* field_type = 0;
			vnl::info::TypeName* field_type_name = 0;
			std::cout << "\"";
			if(field) {
				std::cout << field->name.to_string();
				field_type = type_info->find(field->type.hash);
				field_type_name = &field->type;
			} else {
				std::cout << (vnl::String() << vnl::hex(field_hash)).to_string();
			}
			std::cout << "\" : ";
			dump_sample(in, field_type, field_type_name);
			if(i < size-1) {
				std::cout << ", ";
			}
		}
		std::cout << "}";
		break;
	default:
		in.skip(id, size);
	}
}


int main(int argc, char** argv) {
	
	if(argc < 2) {
		std::cerr << "Usage: vnlrec2json recording.dat" << std::endl;
		return 0;
	}
	
	vnl::internal::global_pool_ = new vnl::GlobalPool();
	
	vnl::io::File file;
	vnl::io::TypeInput in(&file);
	
	file = ::fopen(argv[1], "r");
	if(!file.good()) {
		std::cerr << "ERROR: Unable to open file for reading: " << argv[1] << std::endl;
		return -1;
	}
	
	vnl::RecordHeader header;
	{
		vnl::Pointer<vnl::Value> ptr;
		vnl::read(in, ptr);
		vnl::RecordHeader* p_header = dynamic_cast<vnl::RecordHeader*>(ptr.get());
		if(p_header) {
			header = *p_header;
			::fseek(file, header.header_size, SEEK_SET);
		} else {
			::fseek(file, 0, SEEK_SET);
		}
		in.reset();
	}
	
	type_info = new vnl::Map<vnl::Hash32, vnl::info::Type>();
	if(header.have_type_info) {
		vnl::RecordTypeInfo record_type_info;
		vnl::read(in, record_type_info);
		*type_info = record_type_info.type_map;
		std::cout << "{\"type_info\" : " << vnl::to_string(type_info->values()) << "}" << std::endl;
	} else {
		std::cerr << "INFO: RecordTypeInfo missing!" << std::endl;
	}
	
	config = new vnl::Map<vnl::String, vnl::String>();
	if(header.have_config) {
		vnl::RecordConfig record_config;
		vnl::read(in, record_config);
		*config = record_config.config_map;
		std::cout << "{\"config\" : " << vnl::to_string(*config) << "}" << std::endl;
	} else {
		std::cerr << "INFO: RecordConfig missing!" << std::endl;
	}
	
	vnl::Page* data = vnl::Page::alloc();
	vnl::io::ByteBuffer buf(data);
	vnl::io::TypeOutput out(&buf);
	
	vnl::RecordValue next;
	while(true) {
		vnl::read(in, next);
		if(in.error()) {
			break;
		}
		if(!next.value) {
			continue;
		}
		std::cout << "{\"time\" : " << next.time << ", ";
		if(next.header) {
			std::cout << "\"domain\" : \"" << next.header->dst_topic.domain.to_string() << "\", \"topic\" : \"" << next.header->dst_topic.name.to_string() << "\", ";
		}
		std::cout << "\"value\" : ";
		
		buf.reset();
		out.reset();
		vnl::write(out, next.value.get());
		out.flush();
		buf.flip();
		
		vnl::io::TypeInput in(&buf);
		dump_sample(in, 0, 0);
		
		std::cout << "}" << std::endl;
	}
	
	::fclose(file);
	
}


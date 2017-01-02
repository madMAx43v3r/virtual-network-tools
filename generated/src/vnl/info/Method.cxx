
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/info/Method.hxx>
#include <vnl/Type.hxx>

namespace vnl {
namespace info {

const uint32_t Method::VNI_HASH;
const uint32_t Method::NUM_FIELDS;

Method* Method::create() {
	return vnl::create<Method>();
}

Method* Method::clone() const {
	return vnl::clone<Method>(*this);
}

void Method::destroy() {
	this->Method::~Method();
	return vnl::internal::global_pool_->push_back(this, sizeof(Method));
}

void Method::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xc114cc40); vnl::write(_out, hash);
	_out.putHash(0x539b7130); vnl::write(_out, name);
	_out.putHash(0x5fa779df); vnl::write(_out, type);
	_out.putHash(0x3f42b528); vnl::write(_out, params);
}

void Method::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xc114cc40: vnl::read(_in, hash); break;
			case 0x539b7130: vnl::read(_in, name); break;
			case 0x5fa779df: vnl::read(_in, type); break;
			case 0x3f42b528: vnl::read(_in, params); break;
			default: _in.skip();
		}
	}
}

int Method::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xc114cc40: return 0;
		case 0x539b7130: return 1;
		case 0x5fa779df: return 2;
		case 0x3f42b528: return 3;
		default: return -1;
	}
}

const char* Method::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "hash";
		case 1: return "name";
		case 2: return "type";
		case 3: return "params";
		default: return 0;
	}
}

void Method::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, hash); break;
		case 1: vnl::to_string(_str, name); break;
		case 2: vnl::to_string(_str, type); break;
		case 3: vnl::to_string(_str, params); break;
	}
}

void Method::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, hash); break;
		case 1: vnl::from_string(_str, name); break;
		case 2: vnl::from_string(_str, type); break;
		case 3: vnl::from_string(_str, params); break;
	}
}

void Method::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, hash); break;
		case 1: vnl::write(_out, name); break;
		case 2: vnl::write(_out, type); break;
		case 3: vnl::write(_out, params); break;
		default: _out.putNull();
	}
}

void Method::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, hash); break;
		case 1: vnl::read(_in, name); break;
		case 2: vnl::read(_in, type); break;
		case 3: vnl::read(_in, params); break;
	}
}


} // namespace
} // namespace

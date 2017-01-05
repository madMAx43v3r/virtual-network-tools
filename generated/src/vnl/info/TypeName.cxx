
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/info/TypeName.hxx>
#include <vnl/Type.hxx>

namespace vnl {
namespace info {

const uint32_t TypeName::VNI_HASH;
const uint32_t TypeName::NUM_FIELDS;

TypeName* TypeName::create() {
	return vnl::create<TypeName>();
}

TypeName* TypeName::clone() const {
	return vnl::clone<TypeName>(*this);
}

void TypeName::destroy() {
	this->TypeName::~TypeName();
	return vnl::internal::global_pool_->push_back(this, sizeof(TypeName));
}

void TypeName::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xc114cc40); vnl::write(_out, hash);
	_out.putHash(0x539b7130); vnl::write(_out, name);
	_out.putHash(0xa45ffba); vnl::write(_out, generics);
}

void TypeName::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xc114cc40: vnl::read(_in, hash); break;
			case 0x539b7130: vnl::read(_in, name); break;
			case 0xa45ffba: vnl::read(_in, generics); break;
			default: _in.skip();
		}
	}
}

int TypeName::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xc114cc40: return 0;
		case 0x539b7130: return 1;
		case 0xa45ffba: return 2;
		default: return -1;
	}
}

const char* TypeName::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "hash";
		case 1: return "name";
		case 2: return "generics";
		default: return 0;
	}
}

void TypeName::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, hash); break;
		case 1: vnl::to_string(_str, name); break;
		case 2: vnl::to_string(_str, generics); break;
	}
}

void TypeName::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, hash); break;
		case 1: vnl::from_string(_str, name); break;
		case 2: vnl::from_string(_str, generics); break;
	}
}

void TypeName::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, hash); break;
		case 1: vnl::write(_out, name); break;
		case 2: vnl::write(_out, generics); break;
		default: _out.putNull();
	}
}

void TypeName::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, hash); break;
		case 1: vnl::read(_in, name); break;
		case 2: vnl::read(_in, generics); break;
	}
}


} // namespace
} // namespace
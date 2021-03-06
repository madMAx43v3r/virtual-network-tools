
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/InvalidValueException.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t InvalidValueException::VNI_HASH;
const uint32_t InvalidValueException::NUM_FIELDS;

InvalidValueException::InvalidValueException() {
}

InvalidValueException* InvalidValueException::create() {
	return vnl::create<InvalidValueException>();
}

InvalidValueException* InvalidValueException::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x455aebea: return vnl::create<vnl::InvalidValueException>();
		default: return 0;
	}
}

InvalidValueException* InvalidValueException::clone() const {
	return vnl::clone<InvalidValueException>(*this);
}

void InvalidValueException::destroy() {
	this->InvalidValueException::~InvalidValueException();
	return vnl::internal::global_pool_->push_back(this, sizeof(InvalidValueException));
}

bool InvalidValueException::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x455aebea: return true;
		default: return false;
	}
}

bool InvalidValueException::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x455aebea:
			*this = (const InvalidValueException&)_value; return true;
		default: return false;
	}
}

void InvalidValueException::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xc16d882f); vnl::write(_out, what);
}

void InvalidValueException::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xc16d882f: vnl::read(_in, what); break;
			default: _in.skip();
		}
	}
}

int InvalidValueException::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xc16d882f: return 0;
		default: return -1;
	}
}

const char* InvalidValueException::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "what";
		default: return 0;
	}
}

void InvalidValueException::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, what); break;
	}
}

void InvalidValueException::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, what); break;
	}
}

void InvalidValueException::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, what); break;
		default: _out.putNull();
	}
}

void InvalidValueException::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, what); break;
	}
}

void InvalidValueException::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = what; break;
		default: _var.clear();
	}
}

void InvalidValueException::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(what); break;
	}
}


} // namespace

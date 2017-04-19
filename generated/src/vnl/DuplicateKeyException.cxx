
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/DuplicateKeyException.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t DuplicateKeyException::VNI_HASH;
const uint32_t DuplicateKeyException::NUM_FIELDS;

DuplicateKeyException::DuplicateKeyException() {
}

DuplicateKeyException* DuplicateKeyException::create() {
	return vnl::create<DuplicateKeyException>();
}

DuplicateKeyException* DuplicateKeyException::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x7e6aa525: return vnl::create<vnl::DuplicateKeyException>();
		default: return 0;
	}
}

DuplicateKeyException* DuplicateKeyException::clone() const {
	return vnl::clone<DuplicateKeyException>(*this);
}

void DuplicateKeyException::destroy() {
	this->DuplicateKeyException::~DuplicateKeyException();
	return vnl::internal::global_pool_->push_back(this, sizeof(DuplicateKeyException));
}

bool DuplicateKeyException::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x7e6aa525: return true;
		default: return false;
	}
}

bool DuplicateKeyException::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x7e6aa525:
			*this = (const DuplicateKeyException&)_value; return true;
		default: return false;
	}
}

void DuplicateKeyException::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xc16d882f); vnl::write(_out, what);
}

void DuplicateKeyException::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xc16d882f: vnl::read(_in, what); break;
			default: _in.skip();
		}
	}
}

int DuplicateKeyException::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xc16d882f: return 0;
		default: return -1;
	}
}

const char* DuplicateKeyException::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "what";
		default: return 0;
	}
}

void DuplicateKeyException::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, what); break;
	}
}

void DuplicateKeyException::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, what); break;
	}
}

void DuplicateKeyException::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, what); break;
		default: _out.putNull();
	}
}

void DuplicateKeyException::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, what); break;
	}
}

void DuplicateKeyException::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = what; break;
		default: _var.clear();
	}
}

void DuplicateKeyException::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(what); break;
	}
}


} // namespace

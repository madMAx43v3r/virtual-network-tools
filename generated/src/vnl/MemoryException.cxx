
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/MemoryException.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t MemoryException::VNI_HASH;
const uint32_t MemoryException::NUM_FIELDS;

MemoryException::MemoryException() {
}

MemoryException* MemoryException::create() {
	return vnl::create<MemoryException>();
}

MemoryException* MemoryException::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x4643b1ad: return vnl::create<vnl::MemoryException>();
		default: return 0;
	}
}

MemoryException* MemoryException::clone() const {
	return vnl::clone<MemoryException>(*this);
}

void MemoryException::destroy() {
	this->MemoryException::~MemoryException();
	return vnl::internal::global_pool_->push_back(this, sizeof(MemoryException));
}

bool MemoryException::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x4643b1ad: return true;
		default: return false;
	}
}

bool MemoryException::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x4643b1ad:
			*this = (const MemoryException&)_value; return true;
		default: return false;
	}
}

void MemoryException::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xc16d882f); vnl::write(_out, what);
}

void MemoryException::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xc16d882f: vnl::read(_in, what); break;
			default: _in.skip();
		}
	}
}

int MemoryException::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xc16d882f: return 0;
		default: return -1;
	}
}

const char* MemoryException::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "what";
		default: return 0;
	}
}

void MemoryException::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, what); break;
	}
}

void MemoryException::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, what); break;
	}
}

void MemoryException::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, what); break;
		default: _out.putNull();
	}
}

void MemoryException::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, what); break;
	}
}

void MemoryException::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = what; break;
		default: _var.clear();
	}
}

void MemoryException::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(what); break;
	}
}


} // namespace

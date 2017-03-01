
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/OutOfMemoryException.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t OutOfMemoryException::VNI_HASH;
const uint32_t OutOfMemoryException::NUM_FIELDS;

OutOfMemoryException::OutOfMemoryException() {
}

OutOfMemoryException* OutOfMemoryException::create() {
	return vnl::create<OutOfMemoryException>();
}

OutOfMemoryException* OutOfMemoryException::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x61b281b0: return vnl::create<vnl::OutOfMemoryException>();
		default: return 0;
	}
}

OutOfMemoryException* OutOfMemoryException::clone() const {
	return vnl::clone<OutOfMemoryException>(*this);
}

void OutOfMemoryException::destroy() {
	this->OutOfMemoryException::~OutOfMemoryException();
	return vnl::internal::global_pool_->push_back(this, sizeof(OutOfMemoryException));
}

bool OutOfMemoryException::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x61b281b0: return true;
		default: return false;
	}
}

bool OutOfMemoryException::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x61b281b0:
			*this = (const OutOfMemoryException&)_value; return true;
		default: return false;
	}
}

void OutOfMemoryException::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void OutOfMemoryException::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int OutOfMemoryException::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* OutOfMemoryException::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void OutOfMemoryException::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void OutOfMemoryException::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void OutOfMemoryException::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void OutOfMemoryException::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}

void OutOfMemoryException::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		default: _var.clear();
	}
}

void OutOfMemoryException::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
	}
}


} // namespace
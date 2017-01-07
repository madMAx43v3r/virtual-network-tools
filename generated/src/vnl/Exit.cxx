
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Exit.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t Exit::VNI_HASH;
const uint32_t Exit::NUM_FIELDS;

Exit* Exit::create() {
	return vnl::create<Exit>();
}

Exit* Exit::clone() const {
	return vnl::clone<Exit>(*this);
}

void Exit::destroy() {
	this->Exit::~Exit();
	return vnl::internal::global_pool_->push_back(this, sizeof(Exit));
}

bool Exit::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x3bd088b0: *this = (const Exit&)_value; return true;
		default: return false;
	}
}

void Exit::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void Exit::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int Exit::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* Exit::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void Exit::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void Exit::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void Exit::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void Exit::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}

void Exit::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		default: _var.clear();
	}
}

void Exit::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
	}
}


} // namespace

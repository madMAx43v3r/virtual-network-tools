
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Shutdown.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t Shutdown::VNI_HASH;
const uint32_t Shutdown::NUM_FIELDS;

Shutdown::Shutdown() {
}

Shutdown* Shutdown::create() {
	return vnl::create<Shutdown>();
}

Shutdown* Shutdown::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0xcdc22e1f: return vnl::create<vnl::Shutdown>();
		default: return 0;
	}
}

Shutdown* Shutdown::clone() const {
	return vnl::clone<Shutdown>(*this);
}

void Shutdown::destroy() {
	this->Shutdown::~Shutdown();
	return vnl::internal::global_pool_->push_back(this, sizeof(Shutdown));
}

bool Shutdown::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0xcdc22e1f: return true;
		default: return false;
	}
}

bool Shutdown::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0xcdc22e1f:
			*this = (const Shutdown&)_value; return true;
		default: return false;
	}
}

void Shutdown::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void Shutdown::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int Shutdown::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* Shutdown::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void Shutdown::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void Shutdown::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void Shutdown::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void Shutdown::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}

void Shutdown::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		default: _var.clear();
	}
}

void Shutdown::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
	}
}


} // namespace

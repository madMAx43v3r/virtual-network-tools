
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/IllegalInstruction.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t IllegalInstruction::VNI_HASH;
const uint32_t IllegalInstruction::NUM_FIELDS;

IllegalInstruction::IllegalInstruction() {
}

IllegalInstruction* IllegalInstruction::create() {
	return vnl::create<IllegalInstruction>();
}

IllegalInstruction* IllegalInstruction::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0xf8fa6b14: return vnl::create<vnl::IllegalInstruction>();
		default: return 0;
	}
}

IllegalInstruction* IllegalInstruction::clone() const {
	return vnl::clone<IllegalInstruction>(*this);
}

void IllegalInstruction::destroy() {
	this->IllegalInstruction::~IllegalInstruction();
	return vnl::internal::global_pool_->push_back(this, sizeof(IllegalInstruction));
}

bool IllegalInstruction::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0xf8fa6b14: return true;
		default: return false;
	}
}

bool IllegalInstruction::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0xf8fa6b14:
			*this = (const IllegalInstruction&)_value; return true;
		default: return false;
	}
}

void IllegalInstruction::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void IllegalInstruction::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int IllegalInstruction::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* IllegalInstruction::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void IllegalInstruction::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void IllegalInstruction::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void IllegalInstruction::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void IllegalInstruction::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}

void IllegalInstruction::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		default: _var.clear();
	}
}

void IllegalInstruction::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
	}
}


} // namespace

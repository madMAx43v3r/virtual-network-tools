
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/info/MemoryInfo.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {
namespace info {

const uint32_t MemoryInfo::VNI_HASH;
const uint32_t MemoryInfo::NUM_FIELDS;

MemoryInfo::MemoryInfo() {
	size = 0;
	num_alloc = 0;
	num_used = 0;
}

MemoryInfo* MemoryInfo::create() {
	return vnl::create<MemoryInfo>();
}

MemoryInfo* MemoryInfo::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x734ed4bc: return vnl::create<vnl::info::MemoryInfo>();
		default: return 0;
	}
}

MemoryInfo* MemoryInfo::clone() const {
	return vnl::clone<MemoryInfo>(*this);
}

void MemoryInfo::destroy() {
	this->MemoryInfo::~MemoryInfo();
	return vnl::internal::global_pool_->push_back(this, sizeof(MemoryInfo));
}

bool MemoryInfo::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x734ed4bc: return true;
		default: return false;
	}
}

bool MemoryInfo::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x734ed4bc:
			*this = (const MemoryInfo&)_value; return true;
		default: return false;
	}
}

void MemoryInfo::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0x57eeb48c); vnl::write(_out, size);
	_out.putHash(0x191f6b36); vnl::write(_out, num_alloc);
	_out.putHash(0x602e8daf); vnl::write(_out, num_used);
}

void MemoryInfo::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0x57eeb48c: vnl::read(_in, size); break;
			case 0x191f6b36: vnl::read(_in, num_alloc); break;
			case 0x602e8daf: vnl::read(_in, num_used); break;
			default: _in.skip();
		}
	}
}

int MemoryInfo::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x57eeb48c: return 0;
		case 0x191f6b36: return 1;
		case 0x602e8daf: return 2;
		default: return -1;
	}
}

const char* MemoryInfo::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "size";
		case 1: return "num_alloc";
		case 2: return "num_used";
		default: return 0;
	}
}

void MemoryInfo::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, size); break;
		case 1: vnl::to_string(_str, num_alloc); break;
		case 2: vnl::to_string(_str, num_used); break;
	}
}

void MemoryInfo::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, size); break;
		case 1: vnl::from_string(_str, num_alloc); break;
		case 2: vnl::from_string(_str, num_used); break;
	}
}

void MemoryInfo::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, size); break;
		case 1: vnl::write(_out, num_alloc); break;
		case 2: vnl::write(_out, num_used); break;
		default: _out.putNull();
	}
}

void MemoryInfo::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, size); break;
		case 1: vnl::read(_in, num_alloc); break;
		case 2: vnl::read(_in, num_used); break;
	}
}

void MemoryInfo::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = size; break;
		case 1: _var = num_alloc; break;
		case 2: _var = num_used; break;
		default: _var.clear();
	}
}

void MemoryInfo::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(size); break;
		case 1: _var.to(num_alloc); break;
		case 2: _var.to(num_used); break;
	}
}


} // namespace
} // namespace

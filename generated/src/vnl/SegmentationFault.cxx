
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/SegmentationFault.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t SegmentationFault::VNI_HASH;
const uint32_t SegmentationFault::NUM_FIELDS;

SegmentationFault::SegmentationFault() {
}

SegmentationFault* SegmentationFault::create() {
	return vnl::create<SegmentationFault>();
}

SegmentationFault* SegmentationFault::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x57c2463c: return vnl::create<vnl::SegmentationFault>();
		default: return 0;
	}
}

SegmentationFault* SegmentationFault::clone() const {
	return vnl::clone<SegmentationFault>(*this);
}

void SegmentationFault::destroy() {
	this->SegmentationFault::~SegmentationFault();
	return vnl::internal::global_pool_->push_back(this, sizeof(SegmentationFault));
}

bool SegmentationFault::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x57c2463c: return true;
		default: return false;
	}
}

bool SegmentationFault::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x57c2463c:
			*this = (const SegmentationFault&)_value; return true;
		default: return false;
	}
}

void SegmentationFault::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void SegmentationFault::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int SegmentationFault::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* SegmentationFault::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void SegmentationFault::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void SegmentationFault::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void SegmentationFault::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void SegmentationFault::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}

void SegmentationFault::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		default: _var.clear();
	}
}

void SegmentationFault::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
	}
}


} // namespace

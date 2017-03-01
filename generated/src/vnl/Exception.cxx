
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Exception.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>
#include <vnl/DuplicateKeyException.hxx>
#include <vnl/IOException.hxx>
#include <vnl/IllegalInstruction.hxx>
#include <vnl/MemoryException.hxx>
#include <vnl/NoSuchFieldException.hxx>
#include <vnl/NoSuchKeyException.hxx>
#include <vnl/NoSuchMethodException.hxx>
#include <vnl/NullPointerException.hxx>
#include <vnl/OutOfMemoryException.hxx>
#include <vnl/SegmentationFault.hxx>
#include <vnl/StackOverflow.hxx>
#include <vnl/TimeoutException.hxx>
#include <vnl/TypeMismatchException.hxx>

namespace vnl {

const uint32_t Exception::VNI_HASH;
const uint32_t Exception::NUM_FIELDS;

Exception::Exception() {
}

Exception* Exception::create() {
	return vnl::create<Exception>();
}

Exception* Exception::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x7e6aa525: return vnl::create<vnl::DuplicateKeyException>();
		case 0xabd5ff87: return vnl::create<vnl::IOException>();
		case 0xf8fa6b14: return vnl::create<vnl::IllegalInstruction>();
		case 0x4643b1ad: return vnl::create<vnl::MemoryException>();
		case 0xd7988e27: return vnl::create<vnl::NoSuchFieldException>();
		case 0xd8d131ca: return vnl::create<vnl::NoSuchKeyException>();
		case 0x69a97186: return vnl::create<vnl::NoSuchMethodException>();
		case 0x375698d0: return vnl::create<vnl::NullPointerException>();
		case 0x61b281b0: return vnl::create<vnl::OutOfMemoryException>();
		case 0x57c2463c: return vnl::create<vnl::SegmentationFault>();
		case 0x2cd1d77c: return vnl::create<vnl::StackOverflow>();
		case 0x8c528f1: return vnl::create<vnl::TimeoutException>();
		case 0x493cc6db: return vnl::create<vnl::TypeMismatchException>();
		case 0xbe87903d: return vnl::create<vnl::Exception>();
		default: return 0;
	}
}

Exception* Exception::clone() const {
	return vnl::clone<Exception>(*this);
}

void Exception::destroy() {
	this->Exception::~Exception();
	return vnl::internal::global_pool_->push_back(this, sizeof(Exception));
}

bool Exception::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x7e6aa525: return true;
		case 0xabd5ff87: return true;
		case 0xf8fa6b14: return true;
		case 0x4643b1ad: return true;
		case 0xd7988e27: return true;
		case 0xd8d131ca: return true;
		case 0x69a97186: return true;
		case 0x375698d0: return true;
		case 0x61b281b0: return true;
		case 0x57c2463c: return true;
		case 0x2cd1d77c: return true;
		case 0x8c528f1: return true;
		case 0x493cc6db: return true;
		case 0xbe87903d: return true;
		default: return false;
	}
}

bool Exception::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x7e6aa525:
		case 0xabd5ff87:
		case 0xf8fa6b14:
		case 0x4643b1ad:
		case 0xd7988e27:
		case 0xd8d131ca:
		case 0x69a97186:
		case 0x375698d0:
		case 0x61b281b0:
		case 0x57c2463c:
		case 0x2cd1d77c:
		case 0x8c528f1:
		case 0x493cc6db:
		case 0xbe87903d:
			*this = (const Exception&)_value; return true;
		default: return false;
	}
}

void Exception::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void Exception::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int Exception::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* Exception::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void Exception::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void Exception::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void Exception::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void Exception::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}

void Exception::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		default: _var.clear();
	}
}

void Exception::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
	}
}


} // namespace

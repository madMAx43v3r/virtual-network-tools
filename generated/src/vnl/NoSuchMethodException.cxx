
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/NoSuchMethodException.hxx>
#include <vnl/Type.hxx>

namespace vnl {

const uint32_t NoSuchMethodException::VNI_HASH;
const uint32_t NoSuchMethodException::NUM_FIELDS;

NoSuchMethodException* NoSuchMethodException::create() {
	return vnl::create<NoSuchMethodException>();
}

NoSuchMethodException* NoSuchMethodException::clone() const {
	return vnl::clone<NoSuchMethodException>(*this);
}

void NoSuchMethodException::destroy() {
	this->NoSuchMethodException::~NoSuchMethodException();
	return vnl::internal::global_pool_->push_back(this, sizeof(NoSuchMethodException));
}

void NoSuchMethodException::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void NoSuchMethodException::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int NoSuchMethodException::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* NoSuchMethodException::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void NoSuchMethodException::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void NoSuchMethodException::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void NoSuchMethodException::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void NoSuchMethodException::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}


} // namespace


// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/IOException.hxx>
#include <vnl/Type.hxx>

namespace vnl {

const uint32_t IOException::VNI_HASH;
const uint32_t IOException::NUM_FIELDS;

IOException* IOException::create() {
	return vnl::create<IOException>();
}

IOException* IOException::clone() const {
	return vnl::clone<IOException>(*this);
}

void IOException::destroy() {
	this->IOException::~IOException();
	return vnl::internal::global_pool_->push_back(this, sizeof(IOException));
}

void IOException::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void IOException::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int IOException::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* IOException::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void IOException::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void IOException::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void IOException::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void IOException::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}


} // namespace
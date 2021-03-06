
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Entry.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t Entry::VNI_HASH;
const uint32_t Entry::NUM_FIELDS;

Entry::Entry() {
	version = 0;
}

Entry* Entry::create() {
	return vnl::create<Entry>();
}

Entry* Entry::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x8c46309d: return vnl::create<vnl::Entry>();
		default: return 0;
	}
}

Entry* Entry::clone() const {
	return vnl::clone<Entry>(*this);
}

void Entry::destroy() {
	this->Entry::~Entry();
	return vnl::internal::global_pool_->push_back(this, sizeof(Entry));
}

bool Entry::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x8c46309d: return true;
		default: return false;
	}
}

bool Entry::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x8c46309d:
			*this = (const Entry&)_value; return true;
		default: return false;
	}
}

void Entry::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0x23ff6ebe); vnl::write(_out, key);
	_out.putHash(0x55c30e99); vnl::write(_out, version);
}

void Entry::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0x23ff6ebe: vnl::read(_in, key); break;
			case 0x55c30e99: vnl::read(_in, version); break;
			default: _in.skip();
		}
	}
}

int Entry::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x23ff6ebe: return 0;
		case 0x55c30e99: return 1;
		default: return -1;
	}
}

const char* Entry::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "key";
		case 1: return "version";
		default: return 0;
	}
}

void Entry::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, key); break;
		case 1: vnl::to_string(_str, version); break;
	}
}

void Entry::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, key); break;
		case 1: vnl::from_string(_str, version); break;
	}
}

void Entry::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, key); break;
		case 1: vnl::write(_out, version); break;
		default: _out.putNull();
	}
}

void Entry::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, key); break;
		case 1: vnl::read(_in, version); break;
	}
}

void Entry::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = key; break;
		case 1: _var = version; break;
		default: _var.clear();
	}
}

void Entry::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(key); break;
		case 1: _var.to(version); break;
	}
}


} // namespace

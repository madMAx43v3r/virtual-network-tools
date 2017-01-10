
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/RecordTypeInfo.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t RecordTypeInfo::VNI_HASH;
const uint32_t RecordTypeInfo::NUM_FIELDS;

RecordTypeInfo* RecordTypeInfo::create() {
	return vnl::create<RecordTypeInfo>();
}

RecordTypeInfo* RecordTypeInfo::clone() const {
	return vnl::clone<RecordTypeInfo>(*this);
}

void RecordTypeInfo::destroy() {
	this->RecordTypeInfo::~RecordTypeInfo();
	return vnl::internal::global_pool_->push_back(this, sizeof(RecordTypeInfo));
}

bool RecordTypeInfo::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x9a729ac6: *this = (const RecordTypeInfo&)_value; return true;
		default: return false;
	}
}

void RecordTypeInfo::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0x316d3); vnl::write(_out, type_map);
}

void RecordTypeInfo::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0x316d3: vnl::read(_in, type_map); break;
			default: _in.skip();
		}
	}
}

int RecordTypeInfo::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x316d3: return 0;
		default: return -1;
	}
}

const char* RecordTypeInfo::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "type_map";
		default: return 0;
	}
}

void RecordTypeInfo::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, type_map); break;
	}
}

void RecordTypeInfo::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, type_map); break;
	}
}

void RecordTypeInfo::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, type_map); break;
		default: _out.putNull();
	}
}

void RecordTypeInfo::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, type_map); break;
	}
}

void RecordTypeInfo::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = type_map; break;
		default: _var.clear();
	}
}

void RecordTypeInfo::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(type_map); break;
	}
}


} // namespace

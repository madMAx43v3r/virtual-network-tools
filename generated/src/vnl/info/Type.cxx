
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/info/Type.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {
namespace info {

const uint32_t Type::VNI_HASH;
const uint32_t Type::NUM_FIELDS;

Type::Type() {
	is_struct = 0;
	is_class = 0;
	is_enum = 0;
	is_interface = 0;
	is_object = 0;
}

Type* Type::create() {
	return vnl::create<Type>();
}

Type* Type::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0xbde99c40: return vnl::create<vnl::info::Type>();
		default: return 0;
	}
}

Type* Type::clone() const {
	return vnl::clone<Type>(*this);
}

void Type::destroy() {
	this->Type::~Type();
	return vnl::internal::global_pool_->push_back(this, sizeof(Type));
}

bool Type::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0xbde99c40: return true;
		default: return false;
	}
}

bool Type::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0xbde99c40:
			*this = (const Type&)_value; return true;
		default: return false;
	}
}

void Type::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xc114cc40); vnl::write(_out, hash);
	_out.putHash(0x539b7130); vnl::write(_out, name);
	_out.putHash(0x836a9045); vnl::write(_out, super);
	_out.putHash(0x72700701); vnl::write(_out, is_struct);
	_out.putHash(0x674ff4e3); vnl::write(_out, is_class);
	_out.putHash(0xc1fa0e8c); vnl::write(_out, is_enum);
	_out.putHash(0x3e98de28); vnl::write(_out, is_interface);
	_out.putHash(0x4b4df272); vnl::write(_out, is_object);
	_out.putHash(0x96d44ab3); vnl::write(_out, fields);
	_out.putHash(0x8457c8be); vnl::write(_out, methods);
	_out.putHash(0x7cefe7cf); vnl::write(_out, symbols);
}

void Type::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xc114cc40: vnl::read(_in, hash); break;
			case 0x539b7130: vnl::read(_in, name); break;
			case 0x836a9045: vnl::read(_in, super); break;
			case 0x72700701: vnl::read(_in, is_struct); break;
			case 0x674ff4e3: vnl::read(_in, is_class); break;
			case 0xc1fa0e8c: vnl::read(_in, is_enum); break;
			case 0x3e98de28: vnl::read(_in, is_interface); break;
			case 0x4b4df272: vnl::read(_in, is_object); break;
			case 0x96d44ab3: vnl::read(_in, fields); break;
			case 0x8457c8be: vnl::read(_in, methods); break;
			case 0x7cefe7cf: vnl::read(_in, symbols); break;
			default: _in.skip();
		}
	}
}

int Type::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xc114cc40: return 0;
		case 0x539b7130: return 1;
		case 0x836a9045: return 2;
		case 0x72700701: return 3;
		case 0x674ff4e3: return 4;
		case 0xc1fa0e8c: return 5;
		case 0x3e98de28: return 6;
		case 0x4b4df272: return 7;
		case 0x96d44ab3: return 8;
		case 0x8457c8be: return 9;
		case 0x7cefe7cf: return 10;
		default: return -1;
	}
}

const char* Type::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "hash";
		case 1: return "name";
		case 2: return "super";
		case 3: return "is_struct";
		case 4: return "is_class";
		case 5: return "is_enum";
		case 6: return "is_interface";
		case 7: return "is_object";
		case 8: return "fields";
		case 9: return "methods";
		case 10: return "symbols";
		default: return 0;
	}
}

void Type::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, hash); break;
		case 1: vnl::to_string(_str, name); break;
		case 2: vnl::to_string(_str, super); break;
		case 3: vnl::to_string(_str, is_struct); break;
		case 4: vnl::to_string(_str, is_class); break;
		case 5: vnl::to_string(_str, is_enum); break;
		case 6: vnl::to_string(_str, is_interface); break;
		case 7: vnl::to_string(_str, is_object); break;
		case 8: vnl::to_string(_str, fields); break;
		case 9: vnl::to_string(_str, methods); break;
		case 10: vnl::to_string(_str, symbols); break;
	}
}

void Type::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, hash); break;
		case 1: vnl::from_string(_str, name); break;
		case 2: vnl::from_string(_str, super); break;
		case 3: vnl::from_string(_str, is_struct); break;
		case 4: vnl::from_string(_str, is_class); break;
		case 5: vnl::from_string(_str, is_enum); break;
		case 6: vnl::from_string(_str, is_interface); break;
		case 7: vnl::from_string(_str, is_object); break;
		case 8: vnl::from_string(_str, fields); break;
		case 9: vnl::from_string(_str, methods); break;
		case 10: vnl::from_string(_str, symbols); break;
	}
}

void Type::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, hash); break;
		case 1: vnl::write(_out, name); break;
		case 2: vnl::write(_out, super); break;
		case 3: vnl::write(_out, is_struct); break;
		case 4: vnl::write(_out, is_class); break;
		case 5: vnl::write(_out, is_enum); break;
		case 6: vnl::write(_out, is_interface); break;
		case 7: vnl::write(_out, is_object); break;
		case 8: vnl::write(_out, fields); break;
		case 9: vnl::write(_out, methods); break;
		case 10: vnl::write(_out, symbols); break;
		default: _out.putNull();
	}
}

void Type::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, hash); break;
		case 1: vnl::read(_in, name); break;
		case 2: vnl::read(_in, super); break;
		case 3: vnl::read(_in, is_struct); break;
		case 4: vnl::read(_in, is_class); break;
		case 5: vnl::read(_in, is_enum); break;
		case 6: vnl::read(_in, is_interface); break;
		case 7: vnl::read(_in, is_object); break;
		case 8: vnl::read(_in, fields); break;
		case 9: vnl::read(_in, methods); break;
		case 10: vnl::read(_in, symbols); break;
	}
}

void Type::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = hash; break;
		case 1: _var = name; break;
		case 2: _var = super; break;
		case 3: _var = is_struct; break;
		case 4: _var = is_class; break;
		case 5: _var = is_enum; break;
		case 6: _var = is_interface; break;
		case 7: _var = is_object; break;
		case 8: _var = fields; break;
		case 9: _var = methods; break;
		case 10: _var = symbols; break;
		default: _var.clear();
	}
}

void Type::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(hash); break;
		case 1: _var.to(name); break;
		case 2: _var.to(super); break;
		case 3: _var.to(is_struct); break;
		case 4: _var.to(is_class); break;
		case 5: _var.to(is_enum); break;
		case 6: _var.to(is_interface); break;
		case 7: _var.to(is_object); break;
		case 8: _var.to(fields); break;
		case 9: _var.to(methods); break;
		case 10: _var.to(symbols); break;
	}
}


} // namespace
} // namespace

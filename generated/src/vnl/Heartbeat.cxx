
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Heartbeat.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t Heartbeat::VNI_HASH;
const uint32_t Heartbeat::NUM_FIELDS;

Heartbeat* Heartbeat::create() {
	return vnl::create<Heartbeat>();
}

Heartbeat* Heartbeat::clone() const {
	return vnl::clone<Heartbeat>(*this);
}

void Heartbeat::destroy() {
	this->Heartbeat::~Heartbeat();
	return vnl::internal::global_pool_->push_back(this, sizeof(Heartbeat));
}

bool Heartbeat::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0xa262a675: *this = (const Heartbeat&)_value; return true;
		default: return false;
	}
}

void Heartbeat::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0x85aba286); vnl::write(_out, src_mac);
	_out.putHash(0x5fa779df); vnl::write(_out, type);
	_out.putHash(0x5190a58c); vnl::write(_out, domain);
	_out.putHash(0xf68c6937); vnl::write(_out, topic);
	_out.putHash(0xd129c896); vnl::write(_out, interval);
	_out.putHash(0xcaacc145); vnl::write(_out, info);
}

void Heartbeat::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0x85aba286: vnl::read(_in, src_mac); break;
			case 0x5fa779df: vnl::read(_in, type); break;
			case 0x5190a58c: vnl::read(_in, domain); break;
			case 0xf68c6937: vnl::read(_in, topic); break;
			case 0xd129c896: vnl::read(_in, interval); break;
			case 0xcaacc145: vnl::read(_in, info); break;
			default: _in.skip();
		}
	}
}

int Heartbeat::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x85aba286: return 0;
		case 0x5fa779df: return 1;
		case 0x5190a58c: return 2;
		case 0xf68c6937: return 3;
		case 0xd129c896: return 4;
		case 0xcaacc145: return 5;
		default: return -1;
	}
}

const char* Heartbeat::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "src_mac";
		case 1: return "type";
		case 2: return "domain";
		case 3: return "topic";
		case 4: return "interval";
		case 5: return "info";
		default: return 0;
	}
}

void Heartbeat::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, src_mac); break;
		case 1: vnl::to_string(_str, type); break;
		case 2: vnl::to_string(_str, domain); break;
		case 3: vnl::to_string(_str, topic); break;
		case 4: vnl::to_string(_str, interval); break;
		case 5: vnl::to_string(_str, info); break;
	}
}

void Heartbeat::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, src_mac); break;
		case 1: vnl::from_string(_str, type); break;
		case 2: vnl::from_string(_str, domain); break;
		case 3: vnl::from_string(_str, topic); break;
		case 4: vnl::from_string(_str, interval); break;
		case 5: vnl::from_string(_str, info); break;
	}
}

void Heartbeat::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, src_mac); break;
		case 1: vnl::write(_out, type); break;
		case 2: vnl::write(_out, domain); break;
		case 3: vnl::write(_out, topic); break;
		case 4: vnl::write(_out, interval); break;
		case 5: vnl::write(_out, info); break;
		default: _out.putNull();
	}
}

void Heartbeat::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, src_mac); break;
		case 1: vnl::read(_in, type); break;
		case 2: vnl::read(_in, domain); break;
		case 3: vnl::read(_in, topic); break;
		case 4: vnl::read(_in, interval); break;
		case 5: vnl::read(_in, info); break;
	}
}

void Heartbeat::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = src_mac; break;
		case 1: _var = type; break;
		case 2: _var = domain; break;
		case 3: _var = topic; break;
		case 4: _var = interval; break;
		case 5: _var = info; break;
		default: _var.clear();
	}
}

void Heartbeat::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(src_mac); break;
		case 1: _var.to(type); break;
		case 2: _var.to(domain); break;
		case 3: _var.to(topic); break;
		case 4: _var.to(interval); break;
		case 5: _var.to(info); break;
	}
}


} // namespace

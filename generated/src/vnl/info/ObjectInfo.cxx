
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/info/ObjectInfo.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {
namespace info {

const uint32_t ObjectInfo::VNI_HASH;
const uint32_t ObjectInfo::NUM_FIELDS;

ObjectInfo::ObjectInfo() {
	time = 0;
	spawn_time = 0;
	idle_time = 0;
	num_cycles = 0;
	num_msg_sent = 0;
	num_msg_received = 0;
	num_msg_dropped = 0;
	send_latency_sum = 0;
	receive_latency_sum = 0;
}

ObjectInfo* ObjectInfo::create() {
	return vnl::create<ObjectInfo>();
}

ObjectInfo* ObjectInfo::create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x6400b0b3: return vnl::create<vnl::info::ObjectInfo>();
		default: return 0;
	}
}

ObjectInfo* ObjectInfo::clone() const {
	return vnl::clone<ObjectInfo>(*this);
}

void ObjectInfo::destroy() {
	this->ObjectInfo::~ObjectInfo();
	return vnl::internal::global_pool_->push_back(this, sizeof(ObjectInfo));
}

bool ObjectInfo::is_assignable(vnl::Hash32 hash) {
	switch(hash) {
		case 0x6400b0b3: return true;
		default: return false;
	}
}

bool ObjectInfo::assign(const vnl::Value& _value) {
	switch(_value.get_vni_hash()) {
		case 0x6400b0b3:
			*this = (const ObjectInfo&)_value; return true;
		default: return false;
	}
}

void ObjectInfo::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xaf3e4ff0); vnl::write(_out, time);
	_out.putHash(0xa5c8937c); vnl::write(_out, spawn_time);
	_out.putHash(0xb8fc78eb); vnl::write(_out, idle_time);
	_out.putHash(0x7fd711c); vnl::write(_out, num_cycles);
	_out.putHash(0xd6d6fb05); vnl::write(_out, num_msg_sent);
	_out.putHash(0x7f0e60e); vnl::write(_out, num_msg_received);
	_out.putHash(0xa065ff2d); vnl::write(_out, num_msg_dropped);
	_out.putHash(0x14714094); vnl::write(_out, send_latency_sum);
	_out.putHash(0x7094a69f); vnl::write(_out, receive_latency_sum);
	_out.putHash(0x74b25275); vnl::write(_out, sources);
	_out.putHash(0xf1403223); vnl::write(_out, input_nodes);
	_out.putHash(0xa637ecaf); vnl::write(_out, input_channels);
	_out.putHash(0x420d74); vnl::write(_out, output_channels);
	_out.putHash(0xe335406f); vnl::write(_out, input_pins);
	_out.putHash(0xcc9382b); vnl::write(_out, output_pins);
	_out.putHash(0x6d2d01a4); vnl::write(_out, clients);
}

void ObjectInfo::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xaf3e4ff0: vnl::read(_in, time); break;
			case 0xa5c8937c: vnl::read(_in, spawn_time); break;
			case 0xb8fc78eb: vnl::read(_in, idle_time); break;
			case 0x7fd711c: vnl::read(_in, num_cycles); break;
			case 0xd6d6fb05: vnl::read(_in, num_msg_sent); break;
			case 0x7f0e60e: vnl::read(_in, num_msg_received); break;
			case 0xa065ff2d: vnl::read(_in, num_msg_dropped); break;
			case 0x14714094: vnl::read(_in, send_latency_sum); break;
			case 0x7094a69f: vnl::read(_in, receive_latency_sum); break;
			case 0x74b25275: vnl::read(_in, sources); break;
			case 0xf1403223: vnl::read(_in, input_nodes); break;
			case 0xa637ecaf: vnl::read(_in, input_channels); break;
			case 0x420d74: vnl::read(_in, output_channels); break;
			case 0xe335406f: vnl::read(_in, input_pins); break;
			case 0xcc9382b: vnl::read(_in, output_pins); break;
			case 0x6d2d01a4: vnl::read(_in, clients); break;
			default: _in.skip();
		}
	}
}

int ObjectInfo::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xaf3e4ff0: return 0;
		case 0xa5c8937c: return 1;
		case 0xb8fc78eb: return 2;
		case 0x7fd711c: return 3;
		case 0xd6d6fb05: return 4;
		case 0x7f0e60e: return 5;
		case 0xa065ff2d: return 6;
		case 0x14714094: return 7;
		case 0x7094a69f: return 8;
		case 0x74b25275: return 9;
		case 0xf1403223: return 10;
		case 0xa637ecaf: return 11;
		case 0x420d74: return 12;
		case 0xe335406f: return 13;
		case 0xcc9382b: return 14;
		case 0x6d2d01a4: return 15;
		default: return -1;
	}
}

const char* ObjectInfo::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "time";
		case 1: return "spawn_time";
		case 2: return "idle_time";
		case 3: return "num_cycles";
		case 4: return "num_msg_sent";
		case 5: return "num_msg_received";
		case 6: return "num_msg_dropped";
		case 7: return "send_latency_sum";
		case 8: return "receive_latency_sum";
		case 9: return "sources";
		case 10: return "input_nodes";
		case 11: return "input_channels";
		case 12: return "output_channels";
		case 13: return "input_pins";
		case 14: return "output_pins";
		case 15: return "clients";
		default: return 0;
	}
}

void ObjectInfo::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, time); break;
		case 1: vnl::to_string(_str, spawn_time); break;
		case 2: vnl::to_string(_str, idle_time); break;
		case 3: vnl::to_string(_str, num_cycles); break;
		case 4: vnl::to_string(_str, num_msg_sent); break;
		case 5: vnl::to_string(_str, num_msg_received); break;
		case 6: vnl::to_string(_str, num_msg_dropped); break;
		case 7: vnl::to_string(_str, send_latency_sum); break;
		case 8: vnl::to_string(_str, receive_latency_sum); break;
		case 9: vnl::to_string(_str, sources); break;
		case 10: vnl::to_string(_str, input_nodes); break;
		case 11: vnl::to_string(_str, input_channels); break;
		case 12: vnl::to_string(_str, output_channels); break;
		case 13: vnl::to_string(_str, input_pins); break;
		case 14: vnl::to_string(_str, output_pins); break;
		case 15: vnl::to_string(_str, clients); break;
	}
}

void ObjectInfo::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, time); break;
		case 1: vnl::from_string(_str, spawn_time); break;
		case 2: vnl::from_string(_str, idle_time); break;
		case 3: vnl::from_string(_str, num_cycles); break;
		case 4: vnl::from_string(_str, num_msg_sent); break;
		case 5: vnl::from_string(_str, num_msg_received); break;
		case 6: vnl::from_string(_str, num_msg_dropped); break;
		case 7: vnl::from_string(_str, send_latency_sum); break;
		case 8: vnl::from_string(_str, receive_latency_sum); break;
		case 9: vnl::from_string(_str, sources); break;
		case 10: vnl::from_string(_str, input_nodes); break;
		case 11: vnl::from_string(_str, input_channels); break;
		case 12: vnl::from_string(_str, output_channels); break;
		case 13: vnl::from_string(_str, input_pins); break;
		case 14: vnl::from_string(_str, output_pins); break;
		case 15: vnl::from_string(_str, clients); break;
	}
}

void ObjectInfo::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, time); break;
		case 1: vnl::write(_out, spawn_time); break;
		case 2: vnl::write(_out, idle_time); break;
		case 3: vnl::write(_out, num_cycles); break;
		case 4: vnl::write(_out, num_msg_sent); break;
		case 5: vnl::write(_out, num_msg_received); break;
		case 6: vnl::write(_out, num_msg_dropped); break;
		case 7: vnl::write(_out, send_latency_sum); break;
		case 8: vnl::write(_out, receive_latency_sum); break;
		case 9: vnl::write(_out, sources); break;
		case 10: vnl::write(_out, input_nodes); break;
		case 11: vnl::write(_out, input_channels); break;
		case 12: vnl::write(_out, output_channels); break;
		case 13: vnl::write(_out, input_pins); break;
		case 14: vnl::write(_out, output_pins); break;
		case 15: vnl::write(_out, clients); break;
		default: _out.putNull();
	}
}

void ObjectInfo::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, time); break;
		case 1: vnl::read(_in, spawn_time); break;
		case 2: vnl::read(_in, idle_time); break;
		case 3: vnl::read(_in, num_cycles); break;
		case 4: vnl::read(_in, num_msg_sent); break;
		case 5: vnl::read(_in, num_msg_received); break;
		case 6: vnl::read(_in, num_msg_dropped); break;
		case 7: vnl::read(_in, send_latency_sum); break;
		case 8: vnl::read(_in, receive_latency_sum); break;
		case 9: vnl::read(_in, sources); break;
		case 10: vnl::read(_in, input_nodes); break;
		case 11: vnl::read(_in, input_channels); break;
		case 12: vnl::read(_in, output_channels); break;
		case 13: vnl::read(_in, input_pins); break;
		case 14: vnl::read(_in, output_pins); break;
		case 15: vnl::read(_in, clients); break;
	}
}

void ObjectInfo::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = time; break;
		case 1: _var = spawn_time; break;
		case 2: _var = idle_time; break;
		case 3: _var = num_cycles; break;
		case 4: _var = num_msg_sent; break;
		case 5: _var = num_msg_received; break;
		case 6: _var = num_msg_dropped; break;
		case 7: _var = send_latency_sum; break;
		case 8: _var = receive_latency_sum; break;
		case 9: _var = sources; break;
		case 10: _var = input_nodes; break;
		case 11: _var = input_channels; break;
		case 12: _var = output_channels; break;
		case 13: _var = input_pins; break;
		case 14: _var = output_pins; break;
		case 15: _var = clients; break;
		default: _var.clear();
	}
}

void ObjectInfo::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(time); break;
		case 1: _var.to(spawn_time); break;
		case 2: _var.to(idle_time); break;
		case 3: _var.to(num_cycles); break;
		case 4: _var.to(num_msg_sent); break;
		case 5: _var.to(num_msg_received); break;
		case 6: _var.to(num_msg_dropped); break;
		case 7: _var.to(send_latency_sum); break;
		case 8: _var.to(receive_latency_sum); break;
		case 9: _var.to(sources); break;
		case 10: _var.to(input_nodes); break;
		case 11: _var.to(input_channels); break;
		case 12: _var.to(output_channels); break;
		case 13: _var.to(input_pins); break;
		case 14: _var.to(output_pins); break;
		case 15: _var.to(clients); break;
	}
}


} // namespace
} // namespace

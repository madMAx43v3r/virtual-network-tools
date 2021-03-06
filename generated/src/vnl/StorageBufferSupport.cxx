
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/StorageBufferSupport.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t StorageBufferBase::VNI_HASH;
const uint32_t StorageBufferBase::NUM_FIELDS;

StorageBufferBase::StorageBufferBase(const vnl::String& domain_, const vnl::String& topic_)
	:	vnl::Object::Object(domain_, topic_)
{
	vnl::read_config(domain_, topic_, "topics", topics);
}

int StorageBufferBase::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0x604b2647: return 1;
		case 0xd26001ae: return 2;
		case 0x22dd6aa2: return 3;
		default: return -1;
	}
}

const char* StorageBufferBase::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_msg_timeout";
		case 2: return "vnl_heartbeat_interval";
		case 3: return "topics";
		default: return 0;
	}
}

void StorageBufferBase::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_msg_timeout); break;
		case 2: vnl::to_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::to_string(_str, topics); break;
	}
}

void StorageBufferBase::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_msg_timeout); break;
		case 2: vnl::from_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::from_string(_str, topics); break;
	}
}

void StorageBufferBase::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_msg_timeout); break;
		case 2: vnl::write(_out, vnl_heartbeat_interval); break;
		case 3: vnl::write(_out, topics); break;
		default: _out.putNull();
	}
}

void StorageBufferBase::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_msg_timeout); break;
		case 2: vnl::read(_in, vnl_heartbeat_interval); break;
		case 3: vnl::read(_in, topics); break;
	}
}

void StorageBufferBase::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = vnl_log_level; break;
		case 1: _var = vnl_msg_timeout; break;
		case 2: _var = vnl_heartbeat_interval; break;
		case 3: _var = topics; break;
		default: _var.clear();
	}
}

void StorageBufferBase::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(vnl_log_level); break;
		case 1: _var.to(vnl_msg_timeout); break;
		case 2: _var.to(vnl_heartbeat_interval); break;
		case 3: _var.to(topics); break;
	}
}

bool StorageBufferBase::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
	switch(_hash) {
	case 0x22dd6aa2: 
		if(_num_args == 1) {
			vnl::read(_in, topics);
			return true;
		}
		break;
	case 0x53e783cb: 
		switch(_num_args) {
			case 1: {
				vnl::Pointer<vnl::Entry > value;
				vnl::read(_in, value);
				if(!_in.error()) {
					put_entry(value);
					return true;
				}
			}
			break;
		}
		break;
	case 0x6be27404: 
		switch(_num_args) {
			case 1: {
				vnl::Hash64 key;
				vnl::read(_in, key);
				if(!_in.error()) {
					delete_entry(key);
					return true;
				}
			}
			break;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

bool StorageBufferBase::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
	switch(_hash) {
	case 0x22dd6aa2: 
		if(_num_args == 0) {
			vnl::write(_out, topics);
			return true;
		}
		break;
	case 0x2d43064b: 
		switch(_num_args) {
			case 1: {
				vnl::Hash64 key;
				vnl::read(_in, key);
				if(!_in.error()) {
					vnl::Pointer<vnl::Entry > _res = get_entry(key);
					vnl::write(_out, _res);
					return true;
				}
			}
			break;
		}
		break;
	case 0xdc37fd46: 
		switch(_num_args) {
			case 1: {
				vnl::Array<vnl::Hash64 > keys;
				vnl::read(_in, keys);
				if(!_in.error()) {
					vnl::Array<vnl::Pointer<vnl::Entry > > _res = get_entries(keys);
					vnl::write(_out, _res);
					return true;
				}
			}
			break;
		}
		break;
	}
	return Super::vni_const_call(_in, _hash, _num_args, _out);
}

bool StorageBufferBase::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->get_vni_hash()) {
	case 0x8c46309d: handle(*((vnl::Entry*)_sample), *_packet); return true;
	}
	return Super::handle_switch(_sample, _packet);
}

bool StorageBufferBase::handle_switch(vnl::Value* _sample, vnl::Basic* _input) {
	switch(_sample->get_vni_hash()) {
	case 0x8c46309d: handle(*((vnl::Entry*)_sample), _input); return true;
	}
	return Super::handle_switch(_sample, _input);
}


} // namespace

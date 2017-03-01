
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/DatabaseSupport.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t DatabaseBase::VNI_HASH;
const uint32_t DatabaseBase::NUM_FIELDS;

DatabaseBase::DatabaseBase(const vnl::String& domain_, const vnl::String& topic_)
	:	vnl::Object::Object(domain_, topic_)
{
	filename = "database.dat";
	interval = 1000000;
	readonly = false;
	ignore_errors = false;
	truncate = false;
	vnl::read_config(domain_, topic_, "filename", filename);
	vnl::read_config(domain_, topic_, "interval", interval);
	vnl::read_config(domain_, topic_, "readonly", readonly);
	vnl::read_config(domain_, topic_, "ignore_errors", ignore_errors);
	vnl::read_config(domain_, topic_, "truncate", truncate);
}

int DatabaseBase::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0x604b2647: return 1;
		case 0xd26001ae: return 2;
		case 0xb60d3446: return 3;
		case 0xd129c896: return 4;
		case 0x972da0ea: return 5;
		case 0x2d7512a8: return 6;
		case 0x1725750d: return 7;
		default: return -1;
	}
}

const char* DatabaseBase::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_msg_timeout";
		case 2: return "vnl_heartbeat_interval";
		case 3: return "filename";
		case 4: return "interval";
		case 5: return "readonly";
		case 6: return "ignore_errors";
		case 7: return "truncate";
		default: return 0;
	}
}

void DatabaseBase::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_msg_timeout); break;
		case 2: vnl::to_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::to_string(_str, filename); break;
		case 4: vnl::to_string(_str, interval); break;
		case 5: vnl::to_string(_str, readonly); break;
		case 6: vnl::to_string(_str, ignore_errors); break;
		case 7: vnl::to_string(_str, truncate); break;
	}
}

void DatabaseBase::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_msg_timeout); break;
		case 2: vnl::from_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::from_string(_str, filename); break;
		case 4: vnl::from_string(_str, interval); break;
		case 5: vnl::from_string(_str, readonly); break;
		case 6: vnl::from_string(_str, ignore_errors); break;
		case 7: vnl::from_string(_str, truncate); break;
	}
}

void DatabaseBase::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_msg_timeout); break;
		case 2: vnl::write(_out, vnl_heartbeat_interval); break;
		case 3: vnl::write(_out, filename); break;
		case 4: vnl::write(_out, interval); break;
		case 5: vnl::write(_out, readonly); break;
		case 6: vnl::write(_out, ignore_errors); break;
		case 7: vnl::write(_out, truncate); break;
		default: _out.putNull();
	}
}

void DatabaseBase::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_msg_timeout); break;
		case 2: vnl::read(_in, vnl_heartbeat_interval); break;
		case 3: vnl::read(_in, filename); break;
		case 4: vnl::read(_in, interval); break;
		case 5: vnl::read(_in, readonly); break;
		case 6: vnl::read(_in, ignore_errors); break;
		case 7: vnl::read(_in, truncate); break;
	}
}

void DatabaseBase::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = vnl_log_level; break;
		case 1: _var = vnl_msg_timeout; break;
		case 2: _var = vnl_heartbeat_interval; break;
		case 3: _var = filename; break;
		case 4: _var = interval; break;
		case 5: _var = readonly; break;
		case 6: _var = ignore_errors; break;
		case 7: _var = truncate; break;
		default: _var.clear();
	}
}

void DatabaseBase::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(vnl_log_level); break;
		case 1: _var.to(vnl_msg_timeout); break;
		case 2: _var.to(vnl_heartbeat_interval); break;
		case 3: _var.to(filename); break;
		case 4: _var.to(interval); break;
		case 5: _var.to(readonly); break;
		case 6: _var.to(ignore_errors); break;
		case 7: _var.to(truncate); break;
	}
}

bool DatabaseBase::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
	switch(_hash) {
	case 0xb60d3446: 
		if(_num_args == 1) {
			vnl::read(_in, filename);
			return true;
		}
		break;
	case 0xd129c896: 
		if(_num_args == 1) {
			vnl::read(_in, interval);
			return true;
		}
		break;
	case 0x972da0ea: 
		if(_num_args == 1) {
			vnl::read(_in, readonly);
			return true;
		}
		break;
	case 0x2d7512a8: 
		if(_num_args == 1) {
			vnl::read(_in, ignore_errors);
			return true;
		}
		break;
	case 0x1725750d: 
		if(_num_args == 1) {
			vnl::read(_in, truncate);
			return true;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

bool DatabaseBase::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
	switch(_hash) {
	case 0xb60d3446: 
		if(_num_args == 0) {
			vnl::write(_out, filename);
			return true;
		}
		break;
	case 0xd129c896: 
		if(_num_args == 0) {
			vnl::write(_out, interval);
			return true;
		}
		break;
	case 0x972da0ea: 
		if(_num_args == 0) {
			vnl::write(_out, readonly);
			return true;
		}
		break;
	case 0x2d7512a8: 
		if(_num_args == 0) {
			vnl::write(_out, ignore_errors);
			return true;
		}
		break;
	case 0x1725750d: 
		if(_num_args == 0) {
			vnl::write(_out, truncate);
			return true;
		}
		break;
	}
	return Super::vni_const_call(_in, _hash, _num_args, _out);
}

bool DatabaseBase::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->get_vni_hash()) {
	}
	return Super::handle_switch(_sample, _packet);
}

bool DatabaseBase::handle_switch(vnl::Value* _sample, vnl::Basic* _input) {
	switch(_sample->get_vni_hash()) {
	}
	return Super::handle_switch(_sample, _input);
}


} // namespace

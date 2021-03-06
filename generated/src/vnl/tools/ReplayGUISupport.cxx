
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/tools/ReplayGUISupport.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {
namespace tools {

const uint32_t ReplayGUIBase::VNI_HASH;
const uint32_t ReplayGUIBase::NUM_FIELDS;

ReplayGUIBase::ReplayGUIBase(const vnl::String& domain_, const vnl::String& topic_)
	:	vnl::Object::Object(domain_, topic_)
{
	target_host = "localhost";
	target_port = 4444;
	vnl::read_config(domain_, topic_, "target_host", target_host);
	vnl::read_config(domain_, topic_, "target_port", target_port);
}

int ReplayGUIBase::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0x604b2647: return 1;
		case 0xd26001ae: return 2;
		case 0x97e08f18: return 3;
		case 0x579173b0: return 4;
		default: return -1;
	}
}

const char* ReplayGUIBase::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_msg_timeout";
		case 2: return "vnl_heartbeat_interval";
		case 3: return "target_host";
		case 4: return "target_port";
		default: return 0;
	}
}

void ReplayGUIBase::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_msg_timeout); break;
		case 2: vnl::to_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::to_string(_str, target_host); break;
		case 4: vnl::to_string(_str, target_port); break;
	}
}

void ReplayGUIBase::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_msg_timeout); break;
		case 2: vnl::from_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::from_string(_str, target_host); break;
		case 4: vnl::from_string(_str, target_port); break;
	}
}

void ReplayGUIBase::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_msg_timeout); break;
		case 2: vnl::write(_out, vnl_heartbeat_interval); break;
		case 3: vnl::write(_out, target_host); break;
		case 4: vnl::write(_out, target_port); break;
		default: _out.putNull();
	}
}

void ReplayGUIBase::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_msg_timeout); break;
		case 2: vnl::read(_in, vnl_heartbeat_interval); break;
		case 3: vnl::read(_in, target_host); break;
		case 4: vnl::read(_in, target_port); break;
	}
}

void ReplayGUIBase::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = vnl_log_level; break;
		case 1: _var = vnl_msg_timeout; break;
		case 2: _var = vnl_heartbeat_interval; break;
		case 3: _var = target_host; break;
		case 4: _var = target_port; break;
		default: _var.clear();
	}
}

void ReplayGUIBase::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(vnl_log_level); break;
		case 1: _var.to(vnl_msg_timeout); break;
		case 2: _var.to(vnl_heartbeat_interval); break;
		case 3: _var.to(target_host); break;
		case 4: _var.to(target_port); break;
	}
}

bool ReplayGUIBase::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
	switch(_hash) {
	case 0x97e08f18: 
		if(_num_args == 1) {
			vnl::read(_in, target_host);
			return true;
		}
		break;
	case 0x579173b0: 
		if(_num_args == 1) {
			vnl::read(_in, target_port);
			return true;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

bool ReplayGUIBase::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
	switch(_hash) {
	case 0x97e08f18: 
		if(_num_args == 0) {
			vnl::write(_out, target_host);
			return true;
		}
		break;
	case 0x579173b0: 
		if(_num_args == 0) {
			vnl::write(_out, target_port);
			return true;
		}
		break;
	}
	return Super::vni_const_call(_in, _hash, _num_args, _out);
}

bool ReplayGUIBase::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->get_vni_hash()) {
	case 0xddc3d187: handle(*((vnl::Topic*)_sample), *_packet); return true;
	case 0xf9baa92e: handle(*((vnl::info::PlayerStatus*)_sample), *_packet); return true;
	}
	return Super::handle_switch(_sample, _packet);
}

bool ReplayGUIBase::handle_switch(vnl::Value* _sample, vnl::Basic* _input) {
	switch(_sample->get_vni_hash()) {
	case 0xddc3d187: handle(*((vnl::Topic*)_sample), _input); return true;
	case 0xf9baa92e: handle(*((vnl::info::PlayerStatus*)_sample), _input); return true;
	}
	return Super::handle_switch(_sample, _input);
}


} // namespace
} // namespace

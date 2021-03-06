
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/tools/AdminGUISupport.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {
namespace tools {

const uint32_t AdminGUIBase::VNI_HASH;
const uint32_t AdminGUIBase::NUM_FIELDS;

AdminGUIBase::AdminGUIBase(const vnl::String& domain_, const vnl::String& topic_)
	:	vnl::Object::Object(domain_, topic_)
{
	target_host = "localhost";
	target_port = 8916;
	update_interval = 1000;
	sample_window = 1000000;
	max_sample_rate = 5;
	max_array_size = 100;
	topic_timeout = 3000000;
	vnl::read_config(domain_, topic_, "target_host", target_host);
	vnl::read_config(domain_, topic_, "target_port", target_port);
	vnl::read_config(domain_, topic_, "update_interval", update_interval);
	vnl::read_config(domain_, topic_, "sample_window", sample_window);
	vnl::read_config(domain_, topic_, "max_sample_rate", max_sample_rate);
	vnl::read_config(domain_, topic_, "max_array_size", max_array_size);
	vnl::read_config(domain_, topic_, "topic_timeout", topic_timeout);
}

int AdminGUIBase::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0x604b2647: return 1;
		case 0xd26001ae: return 2;
		case 0x97e08f18: return 3;
		case 0x579173b0: return 4;
		case 0xd04a8e2b: return 5;
		case 0xae47992f: return 6;
		case 0xf6f2233d: return 7;
		case 0xc7e1713a: return 8;
		case 0x817bada2: return 9;
		default: return -1;
	}
}

const char* AdminGUIBase::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_msg_timeout";
		case 2: return "vnl_heartbeat_interval";
		case 3: return "target_host";
		case 4: return "target_port";
		case 5: return "update_interval";
		case 6: return "sample_window";
		case 7: return "max_sample_rate";
		case 8: return "max_array_size";
		case 9: return "topic_timeout";
		default: return 0;
	}
}

void AdminGUIBase::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_msg_timeout); break;
		case 2: vnl::to_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::to_string(_str, target_host); break;
		case 4: vnl::to_string(_str, target_port); break;
		case 5: vnl::to_string(_str, update_interval); break;
		case 6: vnl::to_string(_str, sample_window); break;
		case 7: vnl::to_string(_str, max_sample_rate); break;
		case 8: vnl::to_string(_str, max_array_size); break;
		case 9: vnl::to_string(_str, topic_timeout); break;
	}
}

void AdminGUIBase::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_msg_timeout); break;
		case 2: vnl::from_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::from_string(_str, target_host); break;
		case 4: vnl::from_string(_str, target_port); break;
		case 5: vnl::from_string(_str, update_interval); break;
		case 6: vnl::from_string(_str, sample_window); break;
		case 7: vnl::from_string(_str, max_sample_rate); break;
		case 8: vnl::from_string(_str, max_array_size); break;
		case 9: vnl::from_string(_str, topic_timeout); break;
	}
}

void AdminGUIBase::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_msg_timeout); break;
		case 2: vnl::write(_out, vnl_heartbeat_interval); break;
		case 3: vnl::write(_out, target_host); break;
		case 4: vnl::write(_out, target_port); break;
		case 5: vnl::write(_out, update_interval); break;
		case 6: vnl::write(_out, sample_window); break;
		case 7: vnl::write(_out, max_sample_rate); break;
		case 8: vnl::write(_out, max_array_size); break;
		case 9: vnl::write(_out, topic_timeout); break;
		default: _out.putNull();
	}
}

void AdminGUIBase::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_msg_timeout); break;
		case 2: vnl::read(_in, vnl_heartbeat_interval); break;
		case 3: vnl::read(_in, target_host); break;
		case 4: vnl::read(_in, target_port); break;
		case 5: vnl::read(_in, update_interval); break;
		case 6: vnl::read(_in, sample_window); break;
		case 7: vnl::read(_in, max_sample_rate); break;
		case 8: vnl::read(_in, max_array_size); break;
		case 9: vnl::read(_in, topic_timeout); break;
	}
}

void AdminGUIBase::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = vnl_log_level; break;
		case 1: _var = vnl_msg_timeout; break;
		case 2: _var = vnl_heartbeat_interval; break;
		case 3: _var = target_host; break;
		case 4: _var = target_port; break;
		case 5: _var = update_interval; break;
		case 6: _var = sample_window; break;
		case 7: _var = max_sample_rate; break;
		case 8: _var = max_array_size; break;
		case 9: _var = topic_timeout; break;
		default: _var.clear();
	}
}

void AdminGUIBase::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(vnl_log_level); break;
		case 1: _var.to(vnl_msg_timeout); break;
		case 2: _var.to(vnl_heartbeat_interval); break;
		case 3: _var.to(target_host); break;
		case 4: _var.to(target_port); break;
		case 5: _var.to(update_interval); break;
		case 6: _var.to(sample_window); break;
		case 7: _var.to(max_sample_rate); break;
		case 8: _var.to(max_array_size); break;
		case 9: _var.to(topic_timeout); break;
	}
}

bool AdminGUIBase::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
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
	case 0xd04a8e2b: 
		if(_num_args == 1) {
			vnl::read(_in, update_interval);
			return true;
		}
		break;
	case 0xae47992f: 
		if(_num_args == 1) {
			vnl::read(_in, sample_window);
			return true;
		}
		break;
	case 0xf6f2233d: 
		if(_num_args == 1) {
			vnl::read(_in, max_sample_rate);
			return true;
		}
		break;
	case 0xc7e1713a: 
		if(_num_args == 1) {
			vnl::read(_in, max_array_size);
			return true;
		}
		break;
	case 0x817bada2: 
		if(_num_args == 1) {
			vnl::read(_in, topic_timeout);
			return true;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

bool AdminGUIBase::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
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
	case 0xd04a8e2b: 
		if(_num_args == 0) {
			vnl::write(_out, update_interval);
			return true;
		}
		break;
	case 0xae47992f: 
		if(_num_args == 0) {
			vnl::write(_out, sample_window);
			return true;
		}
		break;
	case 0xf6f2233d: 
		if(_num_args == 0) {
			vnl::write(_out, max_sample_rate);
			return true;
		}
		break;
	case 0xc7e1713a: 
		if(_num_args == 0) {
			vnl::write(_out, max_array_size);
			return true;
		}
		break;
	case 0x817bada2: 
		if(_num_args == 0) {
			vnl::write(_out, topic_timeout);
			return true;
		}
		break;
	}
	return Super::vni_const_call(_in, _hash, _num_args, _out);
}

bool AdminGUIBase::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->get_vni_hash()) {
	case 0xa262a675: handle(*((vnl::Heartbeat*)_sample), *_packet); return true;
	case 0x9df3e6f5: handle(*((vnl::LogMsg*)_sample), *_packet); return true;
	case 0x7aa64297: handle(*((vnl::info::RemoteInfo*)_sample), *_packet); return true;
	case 0xdc558ad: handle(*((vnl::info::TopicInfoList*)_sample), *_packet); return true;
	}
	return Super::handle_switch(_sample, _packet);
}

bool AdminGUIBase::handle_switch(vnl::Value* _sample, vnl::Basic* _input) {
	switch(_sample->get_vni_hash()) {
	case 0xa262a675: handle(*((vnl::Heartbeat*)_sample), _input); return true;
	case 0x9df3e6f5: handle(*((vnl::LogMsg*)_sample), _input); return true;
	case 0x7aa64297: handle(*((vnl::info::RemoteInfo*)_sample), _input); return true;
	case 0xdc558ad: handle(*((vnl::info::TopicInfoList*)_sample), _input); return true;
	}
	return Super::handle_switch(_sample, _input);
}


} // namespace
} // namespace

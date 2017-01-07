
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/ProcessSupport.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {

const uint32_t ProcessBase::VNI_HASH;
const uint32_t ProcessBase::NUM_FIELDS;

int ProcessBase::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0x604b2647: return 1;
		case 0xd26001ae: return 2;
		case 0x539b7130: return 3;
		case 0x498bb8f5: return 4;
		case 0xd04a8e2b: return 5;
		case 0x3a0f0e4b: return 6;
		case 0x36eb5937: return 7;
		default: return -1;
	}
}

const char* ProcessBase::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_msg_timeout";
		case 2: return "vnl_heartbeat_interval";
		case 3: return "name";
		case 4: return "watchdog_interval";
		case 5: return "update_interval";
		case 6: return "stats_interval";
		case 7: return "do_print_stats";
		default: return 0;
	}
}

void ProcessBase::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_msg_timeout); break;
		case 2: vnl::to_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::to_string(_str, name); break;
		case 4: vnl::to_string(_str, watchdog_interval); break;
		case 5: vnl::to_string(_str, update_interval); break;
		case 6: vnl::to_string(_str, stats_interval); break;
		case 7: vnl::to_string(_str, do_print_stats); break;
	}
}

void ProcessBase::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_msg_timeout); break;
		case 2: vnl::from_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::from_string(_str, name); break;
		case 4: vnl::from_string(_str, watchdog_interval); break;
		case 5: vnl::from_string(_str, update_interval); break;
		case 6: vnl::from_string(_str, stats_interval); break;
		case 7: vnl::from_string(_str, do_print_stats); break;
	}
}

void ProcessBase::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_msg_timeout); break;
		case 2: vnl::write(_out, vnl_heartbeat_interval); break;
		case 3: vnl::write(_out, name); break;
		case 4: vnl::write(_out, watchdog_interval); break;
		case 5: vnl::write(_out, update_interval); break;
		case 6: vnl::write(_out, stats_interval); break;
		case 7: vnl::write(_out, do_print_stats); break;
		default: _out.putNull();
	}
}

void ProcessBase::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_msg_timeout); break;
		case 2: vnl::read(_in, vnl_heartbeat_interval); break;
		case 3: vnl::read(_in, name); break;
		case 4: vnl::read(_in, watchdog_interval); break;
		case 5: vnl::read(_in, update_interval); break;
		case 6: vnl::read(_in, stats_interval); break;
		case 7: vnl::read(_in, do_print_stats); break;
	}
}

void ProcessBase::get_field(int _index, vnl::Var& _var) const {
	switch(_index) {
		case 0: _var = vnl_log_level; break;
		case 1: _var = vnl_msg_timeout; break;
		case 2: _var = vnl_heartbeat_interval; break;
		case 3: _var = name; break;
		case 4: _var = watchdog_interval; break;
		case 5: _var = update_interval; break;
		case 6: _var = stats_interval; break;
		case 7: _var = do_print_stats; break;
		default: _var.clear();
	}
}

void ProcessBase::set_field(int _index, const vnl::Var& _var) {
	switch(_index) {
		case 0: _var.to(vnl_log_level); break;
		case 1: _var.to(vnl_msg_timeout); break;
		case 2: _var.to(vnl_heartbeat_interval); break;
		case 3: _var.to(name); break;
		case 4: _var.to(watchdog_interval); break;
		case 5: _var.to(update_interval); break;
		case 6: _var.to(stats_interval); break;
		case 7: _var.to(do_print_stats); break;
	}
}

bool ProcessBase::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
	switch(_hash) {
	case 0x539b7130: 
		if(_num_args == 1) {
			vnl::read(_in, name);
			return true;
		}
		break;
	case 0x498bb8f5: 
		if(_num_args == 1) {
			vnl::read(_in, watchdog_interval);
			return true;
		}
		break;
	case 0xd04a8e2b: 
		if(_num_args == 1) {
			vnl::read(_in, update_interval);
			return true;
		}
		break;
	case 0x3a0f0e4b: 
		if(_num_args == 1) {
			vnl::read(_in, stats_interval);
			return true;
		}
		break;
	case 0x36eb5937: 
		if(_num_args == 1) {
			vnl::read(_in, do_print_stats);
			return true;
		}
		break;
	case 0x87e2d7f: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					shutdown();
					return true;
				}
			}
			break;
		}
		break;
	case 0xaf20300: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					resume_log();
					return true;
				}
			}
			break;
		}
		break;
	case 0x70d1a0f8: 
		switch(_num_args) {
			case 1: {
				vnl::String filter;
				vnl::read(_in, filter);
				if(!_in.error()) {
					set_log_filter(filter);
					return true;
				}
			}
			break;
		}
		break;
	case 0xbb55be0c: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					pause_log();
					return true;
				}
			}
			break;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

bool ProcessBase::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
	switch(_hash) {
	case 0x539b7130: 
		if(_num_args == 0) {
			vnl::write(_out, name);
			return true;
		}
		break;
	case 0x498bb8f5: 
		if(_num_args == 0) {
			vnl::write(_out, watchdog_interval);
			return true;
		}
		break;
	case 0xd04a8e2b: 
		if(_num_args == 0) {
			vnl::write(_out, update_interval);
			return true;
		}
		break;
	case 0x3a0f0e4b: 
		if(_num_args == 0) {
			vnl::write(_out, stats_interval);
			return true;
		}
		break;
	case 0x36eb5937: 
		if(_num_args == 0) {
			vnl::write(_out, do_print_stats);
			return true;
		}
		break;
	case 0xaa2ef6d9: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					vnl::Array<vnl::String > _res = get_class_names();
					vnl::write(_out, _res);
					return true;
				}
			}
			break;
		}
		break;
	case 0xbced8d0d: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					vnl::Array<vnl::Instance > _res = get_objects();
					vnl::write(_out, _res);
					return true;
				}
			}
			break;
		}
		break;
	case 0xd50fc0dd: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					vnl::info::TopicInfoList _res = get_topic_info();
					vnl::write(_out, _res);
					return true;
				}
			}
			break;
		}
		break;
	case 0xf73490b7: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					vnl::Map<vnl::Hash32, vnl::info::Type > _res = get_type_info();
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

bool ProcessBase::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->get_vni_hash()) {
	case 0x417d65c7: handle(*((vnl::Announce*)_sample), *_packet); return true;
	case 0x3bd088b0: handle(*((vnl::Exit*)_sample), *_packet); return true;
	case 0xa262a675: handle(*((vnl::Heartbeat*)_sample), *_packet); return true;
	case 0x9df3e6f5: handle(*((vnl::LogMsg*)_sample), *_packet); return true;
	case 0xcdc22e1f: handle(*((vnl::Shutdown*)_sample), *_packet); return true;
	}
	return Super::handle_switch(_sample, _packet);
}

bool ProcessBase::handle_switch(vnl::Value* _sample, vnl::Basic* _input) {
	switch(_sample->get_vni_hash()) {
	case 0x417d65c7: handle(*((vnl::Announce*)_sample), _input); return true;
	case 0x3bd088b0: handle(*((vnl::Exit*)_sample), _input); return true;
	case 0xa262a675: handle(*((vnl::Heartbeat*)_sample), _input); return true;
	case 0x9df3e6f5: handle(*((vnl::LogMsg*)_sample), _input); return true;
	case 0xcdc22e1f: handle(*((vnl::Shutdown*)_sample), _input); return true;
	}
	return Super::handle_switch(_sample, _input);
}


} // namespace

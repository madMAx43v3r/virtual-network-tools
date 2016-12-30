
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/TcpUplinkSupport.hxx>
#include <vnl/Type.hxx>

namespace vnl {

const uint32_t TcpUplinkBase::VNI_HASH;
const uint32_t TcpUplinkBase::NUM_FIELDS;

int TcpUplinkBase::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0xc30f0945: return 1;
		case 0x279e615d: return 2;
		case 0x55f7671e: return 3;
		case 0x1f5839d4: return 4;
		case 0x5e24337a: return 5;
		default: return -1;
	}
}

const char* TcpUplinkBase::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_max_num_pending";
		case 2: return "send_timeout";
		case 3: return "error_interval";
		case 4: return "are_connected";
		case 5: return "num_drop";
		default: return 0;
	}
}

void TcpUplinkBase::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_max_num_pending); break;
		case 2: vnl::to_string(_str, send_timeout); break;
		case 3: vnl::to_string(_str, error_interval); break;
		case 4: vnl::to_string(_str, are_connected); break;
		case 5: vnl::to_string(_str, num_drop); break;
	}
}

void TcpUplinkBase::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_max_num_pending); break;
		case 2: vnl::from_string(_str, send_timeout); break;
		case 3: vnl::from_string(_str, error_interval); break;
		case 4: vnl::from_string(_str, are_connected); break;
		case 5: vnl::from_string(_str, num_drop); break;
	}
}

void TcpUplinkBase::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_max_num_pending); break;
		case 2: vnl::write(_out, send_timeout); break;
		case 3: vnl::write(_out, error_interval); break;
		case 4: vnl::write(_out, are_connected); break;
		case 5: vnl::write(_out, num_drop); break;
		default: _out.putNull();
	}
}

void TcpUplinkBase::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_max_num_pending); break;
		case 2: vnl::read(_in, send_timeout); break;
		case 3: vnl::read(_in, error_interval); break;
		case 4: vnl::read(_in, are_connected); break;
		case 5: vnl::read(_in, num_drop); break;
	}
}

bool TcpUplinkBase::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
	switch(_hash) {
	case 0x279e615d: 
		if(_num_args == 1) {
			vnl::read(_in, send_timeout);
			return true;
		}
		break;
	case 0x55f7671e: 
		if(_num_args == 1) {
			vnl::read(_in, error_interval);
			return true;
		}
		break;
	case 0x1f5839d4: 
		if(_num_args == 1) {
			vnl::read(_in, are_connected);
			return true;
		}
		break;
	case 0x5e24337a: 
		if(_num_args == 1) {
			vnl::read(_in, num_drop);
			return true;
		}
		break;
	case 0x3bb5d48f: 
		switch(_num_args) {
			case 2: {
				vnl::String domain;
				vnl::read(_in, domain);
				vnl::String topic;
				vnl::read(_in, topic);
				if(!_in.error()) {
					subscribe(domain, topic);
					return true;
				}
			}
			break;
		}
		break;
	case 0x7fbbe878: 
		switch(_num_args) {
			case 2: {
				vnl::String domain;
				vnl::read(_in, domain);
				vnl::String topic;
				vnl::read(_in, topic);
				if(!_in.error()) {
					publish(domain, topic);
					return true;
				}
			}
			break;
		}
		break;
	case 0x983c173d: 
		switch(_num_args) {
			case 1: {
				vnl::Topic topic;
				vnl::read(_in, topic);
				if(!_in.error()) {
					publish(topic);
					return true;
				}
			}
			break;
		}
		break;
	case 0xdc322bca: 
		switch(_num_args) {
			case 1: {
				vnl::Topic topic;
				vnl::read(_in, topic);
				if(!_in.error()) {
					subscribe(topic);
					return true;
				}
			}
			break;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

bool TcpUplinkBase::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
	switch(_hash) {
	case 0x279e615d: 
		if(_num_args == 0) {
			vnl::write(_out, send_timeout);
			return true;
		}
		break;
	case 0x55f7671e: 
		if(_num_args == 0) {
			vnl::write(_out, error_interval);
			return true;
		}
		break;
	case 0x1f5839d4: 
		if(_num_args == 0) {
			vnl::write(_out, are_connected);
			return true;
		}
		break;
	case 0x5e24337a: 
		if(_num_args == 0) {
			vnl::write(_out, num_drop);
			return true;
		}
		break;
	}
	return Super::vni_const_call(_in, _hash, _num_args, _out);
}

bool TcpUplinkBase::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->get_vni_hash()) {
	}
	return Super::handle_switch(_sample, _packet);
}

bool TcpUplinkBase::handle_switch(vnl::Value* _sample, vnl::Basic* _input) {
	switch(_sample->get_vni_hash()) {
	}
	return Super::handle_switch(_sample, _input);
}


} // namespace


// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/TcpServerSupport.hxx>
#include <vnl/Type.hxx>

namespace vnl {

const uint32_t TcpServerBase::VNI_HASH;
const uint32_t TcpServerBase::NUM_FIELDS;

int TcpServerBase::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0x604b2647: return 1;
		case 0xd26001ae: return 2;
		case 0x13e7a893: return 3;
		case 0x55f7671e: return 4;
		case 0xf9aeb41e: return 5;
		case 0x8d249a50: return 6;
		case 0x195f7b11: return 7;
		case 0x4bbaccde: return 8;
		case 0xfd6e8f27: return 9;
		case 0x998b692c: return 10;
		default: return -1;
	}
}

const char* TcpServerBase::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_msg_timeout";
		case 2: return "vnl_heartbeat_interval";
		case 3: return "port";
		case 4: return "error_interval";
		case 5: return "export_topics";
		case 6: return "accept_queue";
		case 7: return "tcp_keepalive";
		case 8: return "tcp_nodelay";
		case 9: return "send_buffer_size";
		case 10: return "receive_buffer_size";
		default: return 0;
	}
}

void TcpServerBase::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_msg_timeout); break;
		case 2: vnl::to_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::to_string(_str, port); break;
		case 4: vnl::to_string(_str, error_interval); break;
		case 5: vnl::to_string(_str, export_topics); break;
		case 6: vnl::to_string(_str, accept_queue); break;
		case 7: vnl::to_string(_str, tcp_keepalive); break;
		case 8: vnl::to_string(_str, tcp_nodelay); break;
		case 9: vnl::to_string(_str, send_buffer_size); break;
		case 10: vnl::to_string(_str, receive_buffer_size); break;
	}
}

void TcpServerBase::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_msg_timeout); break;
		case 2: vnl::from_string(_str, vnl_heartbeat_interval); break;
		case 3: vnl::from_string(_str, port); break;
		case 4: vnl::from_string(_str, error_interval); break;
		case 5: vnl::from_string(_str, export_topics); break;
		case 6: vnl::from_string(_str, accept_queue); break;
		case 7: vnl::from_string(_str, tcp_keepalive); break;
		case 8: vnl::from_string(_str, tcp_nodelay); break;
		case 9: vnl::from_string(_str, send_buffer_size); break;
		case 10: vnl::from_string(_str, receive_buffer_size); break;
	}
}

void TcpServerBase::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_msg_timeout); break;
		case 2: vnl::write(_out, vnl_heartbeat_interval); break;
		case 3: vnl::write(_out, port); break;
		case 4: vnl::write(_out, error_interval); break;
		case 5: vnl::write(_out, export_topics); break;
		case 6: vnl::write(_out, accept_queue); break;
		case 7: vnl::write(_out, tcp_keepalive); break;
		case 8: vnl::write(_out, tcp_nodelay); break;
		case 9: vnl::write(_out, send_buffer_size); break;
		case 10: vnl::write(_out, receive_buffer_size); break;
		default: _out.putNull();
	}
}

void TcpServerBase::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_msg_timeout); break;
		case 2: vnl::read(_in, vnl_heartbeat_interval); break;
		case 3: vnl::read(_in, port); break;
		case 4: vnl::read(_in, error_interval); break;
		case 5: vnl::read(_in, export_topics); break;
		case 6: vnl::read(_in, accept_queue); break;
		case 7: vnl::read(_in, tcp_keepalive); break;
		case 8: vnl::read(_in, tcp_nodelay); break;
		case 9: vnl::read(_in, send_buffer_size); break;
		case 10: vnl::read(_in, receive_buffer_size); break;
	}
}

bool TcpServerBase::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
	switch(_hash) {
	case 0x13e7a893: 
		if(_num_args == 1) {
			vnl::read(_in, port);
			return true;
		}
		break;
	case 0x55f7671e: 
		if(_num_args == 1) {
			vnl::read(_in, error_interval);
			return true;
		}
		break;
	case 0xf9aeb41e: 
		if(_num_args == 1) {
			vnl::read(_in, export_topics);
			return true;
		}
		break;
	case 0x8d249a50: 
		if(_num_args == 1) {
			vnl::read(_in, accept_queue);
			return true;
		}
		break;
	case 0x195f7b11: 
		if(_num_args == 1) {
			vnl::read(_in, tcp_keepalive);
			return true;
		}
		break;
	case 0x4bbaccde: 
		if(_num_args == 1) {
			vnl::read(_in, tcp_nodelay);
			return true;
		}
		break;
	case 0xfd6e8f27: 
		if(_num_args == 1) {
			vnl::read(_in, send_buffer_size);
			return true;
		}
		break;
	case 0x998b692c: 
		if(_num_args == 1) {
			vnl::read(_in, receive_buffer_size);
			return true;
		}
		break;
	case 0x14ffa0f1: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					unsubscribe_all();
					return true;
				}
			}
			break;
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
	case 0xc7428d8c: 
		switch(_num_args) {
			case 2: {
				vnl::String domain;
				vnl::read(_in, domain);
				vnl::String topic;
				vnl::read(_in, topic);
				if(!_in.error()) {
					unpublish(domain, topic);
					return true;
				}
			}
			break;
		}
		break;
	case 0xed7dfb37: 
		switch(_num_args) {
			case 2: {
				vnl::String domain;
				vnl::read(_in, domain);
				vnl::String topic;
				vnl::read(_in, topic);
				if(!_in.error()) {
					unsubscribe(domain, topic);
					return true;
				}
			}
			break;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

bool TcpServerBase::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
	switch(_hash) {
	case 0x13e7a893: 
		if(_num_args == 0) {
			vnl::write(_out, port);
			return true;
		}
		break;
	case 0x55f7671e: 
		if(_num_args == 0) {
			vnl::write(_out, error_interval);
			return true;
		}
		break;
	case 0xf9aeb41e: 
		if(_num_args == 0) {
			vnl::write(_out, export_topics);
			return true;
		}
		break;
	case 0x8d249a50: 
		if(_num_args == 0) {
			vnl::write(_out, accept_queue);
			return true;
		}
		break;
	case 0x195f7b11: 
		if(_num_args == 0) {
			vnl::write(_out, tcp_keepalive);
			return true;
		}
		break;
	case 0x4bbaccde: 
		if(_num_args == 0) {
			vnl::write(_out, tcp_nodelay);
			return true;
		}
		break;
	case 0xfd6e8f27: 
		if(_num_args == 0) {
			vnl::write(_out, send_buffer_size);
			return true;
		}
		break;
	case 0x998b692c: 
		if(_num_args == 0) {
			vnl::write(_out, receive_buffer_size);
			return true;
		}
		break;
	}
	return Super::vni_const_call(_in, _hash, _num_args, _out);
}

bool TcpServerBase::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->get_vni_hash()) {
	}
	return Super::handle_switch(_sample, _packet);
}

bool TcpServerBase::handle_switch(vnl::Value* _sample, vnl::Basic* _input) {
	switch(_sample->get_vni_hash()) {
	}
	return Super::handle_switch(_sample, _input);
}


} // namespace

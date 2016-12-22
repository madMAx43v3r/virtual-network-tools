
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/ObjectSupport.hxx>
#include <vnl/Type.hxx>

namespace vnl {

const uint32_t ObjectBase::VNI_HASH;
const uint32_t ObjectBase::NUM_FIELDS;
const int32_t ObjectBase::ERROR;
const int32_t ObjectBase::WARN;
const int32_t ObjectBase::INFO;
const int32_t ObjectBase::DEBUG;

int ObjectBase::field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0xc30f0945: return 1;
		default: return -1;
	}
}

const char* ObjectBase::field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_max_num_pending";
		default: return 0;
	}
}

void ObjectBase::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_max_num_pending); break;
		default: _str << "{}";
	}
}

void ObjectBase::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_max_num_pending); break;
	}
}

void ObjectBase::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_max_num_pending); break;
		default: _out.putNull();
	}
}

void ObjectBase::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_max_num_pending); break;
	}
}

bool ObjectBase::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
	switch(_hash) {
	case 0x482df535: 
		if(_num_args == 1) {
			vnl::read(_in, vnl_log_level);
			return true;
		}
		break;
	case 0xc30f0945: 
		if(_num_args == 1) {
			vnl::read(_in, vnl_max_num_pending);
			return true;
		}
		break;
	case 0xe8592f85: 
		switch(_num_args) {
			case 0: {
				if(!_in.error()) {
					exit();
					return true;
				}
			}
			break;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

bool ObjectBase::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
	switch(_hash) {
	case 0x482df535: 
		if(_num_args == 0) {
			vnl::write(_out, vnl_log_level);
			return true;
		}
		break;
	case 0xc30f0945: 
		if(_num_args == 0) {
			vnl::write(_out, vnl_max_num_pending);
			return true;
		}
		break;
	}
	return Super::vni_const_call(_in, _hash, _num_args, _out);
}

bool ObjectBase::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->vni_hash()) {
	case 0xcdc22e1f: handle(*((vnl::Shutdown*)_sample), *_packet); return true;
	}
	return Super::handle_switch(_sample, _packet);
}


} // namespace

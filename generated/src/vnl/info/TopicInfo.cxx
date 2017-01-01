
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/info/TopicInfo.hxx>
#include <vnl/Type.hxx>

namespace vnl {
namespace info {

const uint32_t TopicInfo::VNI_HASH;
const uint32_t TopicInfo::NUM_FIELDS;

TopicInfo* TopicInfo::create() {
	return vnl::create<TopicInfo>();
}

TopicInfo* TopicInfo::clone() const {
	return vnl::clone<TopicInfo>(*this);
}

void TopicInfo::destroy() {
	this->TopicInfo::~TopicInfo();
	return vnl::internal::global_pool_->push_back(this, sizeof(TopicInfo));
}

void TopicInfo::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xf68c6937); vnl::write(_out, topic);
	_out.putHash(0x8494c8d8); vnl::write(_out, publishers);
	_out.putHash(0xfcc8b8eb); vnl::write(_out, subscribers);
	_out.putHash(0xf56f7d1e); vnl::write(_out, send_counter);
	_out.putHash(0xbafcf9f0); vnl::write(_out, receive_counter);
	_out.putHash(0x50ad8a03); vnl::write(_out, first_time);
	_out.putHash(0x13c371be); vnl::write(_out, last_time);
}

void TopicInfo::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xf68c6937: vnl::read(_in, topic); break;
			case 0x8494c8d8: vnl::read(_in, publishers); break;
			case 0xfcc8b8eb: vnl::read(_in, subscribers); break;
			case 0xf56f7d1e: vnl::read(_in, send_counter); break;
			case 0xbafcf9f0: vnl::read(_in, receive_counter); break;
			case 0x50ad8a03: vnl::read(_in, first_time); break;
			case 0x13c371be: vnl::read(_in, last_time); break;
			default: _in.skip();
		}
	}
}

int TopicInfo::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xf68c6937: return 0;
		case 0x8494c8d8: return 1;
		case 0xfcc8b8eb: return 2;
		case 0xf56f7d1e: return 3;
		case 0xbafcf9f0: return 4;
		case 0x50ad8a03: return 5;
		case 0x13c371be: return 6;
		default: return -1;
	}
}

const char* TopicInfo::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "topic";
		case 1: return "publishers";
		case 2: return "subscribers";
		case 3: return "send_counter";
		case 4: return "receive_counter";
		case 5: return "first_time";
		case 6: return "last_time";
		default: return 0;
	}
}

void TopicInfo::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, topic); break;
		case 1: vnl::to_string(_str, publishers); break;
		case 2: vnl::to_string(_str, subscribers); break;
		case 3: vnl::to_string(_str, send_counter); break;
		case 4: vnl::to_string(_str, receive_counter); break;
		case 5: vnl::to_string(_str, first_time); break;
		case 6: vnl::to_string(_str, last_time); break;
	}
}

void TopicInfo::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, topic); break;
		case 1: vnl::from_string(_str, publishers); break;
		case 2: vnl::from_string(_str, subscribers); break;
		case 3: vnl::from_string(_str, send_counter); break;
		case 4: vnl::from_string(_str, receive_counter); break;
		case 5: vnl::from_string(_str, first_time); break;
		case 6: vnl::from_string(_str, last_time); break;
	}
}

void TopicInfo::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, topic); break;
		case 1: vnl::write(_out, publishers); break;
		case 2: vnl::write(_out, subscribers); break;
		case 3: vnl::write(_out, send_counter); break;
		case 4: vnl::write(_out, receive_counter); break;
		case 5: vnl::write(_out, first_time); break;
		case 6: vnl::write(_out, last_time); break;
		default: _out.putNull();
	}
}

void TopicInfo::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, topic); break;
		case 1: vnl::read(_in, publishers); break;
		case 2: vnl::read(_in, subscribers); break;
		case 3: vnl::read(_in, send_counter); break;
		case 4: vnl::read(_in, receive_counter); break;
		case 5: vnl::read(_in, first_time); break;
		case 6: vnl::read(_in, last_time); break;
	}
}


} // namespace
} // namespace

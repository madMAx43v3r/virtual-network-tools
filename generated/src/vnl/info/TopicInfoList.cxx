
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/info/TopicInfoList.hxx>
#include <vnl/Type.hxx>

namespace vnl {
namespace info {

const uint32_t TopicInfoList::VNI_HASH;
const uint32_t TopicInfoList::NUM_FIELDS;

TopicInfoList* TopicInfoList::create() {
	return vnl::create<TopicInfoList>();
}

TopicInfoList* TopicInfoList::clone() const {
	return vnl::clone<TopicInfoList>(*this);
}

void TopicInfoList::destroy() {
	this->TopicInfoList::~TopicInfoList();
	return vnl::internal::global_pool_->push_back(this, sizeof(TopicInfoList));
}

void TopicInfoList::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0xaf3e4ff0); vnl::write(_out, time);
	_out.putHash(0x22dd6aa2); vnl::write(_out, topics);
}

void TopicInfoList::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0xaf3e4ff0: vnl::read(_in, time); break;
			case 0x22dd6aa2: vnl::read(_in, topics); break;
			default: _in.skip();
		}
	}
}

int TopicInfoList::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0xaf3e4ff0: return 0;
		case 0x22dd6aa2: return 1;
		default: return -1;
	}
}

const char* TopicInfoList::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "time";
		case 1: return "topics";
		default: return 0;
	}
}

void TopicInfoList::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, time); break;
		case 1: vnl::to_string(_str, topics); break;
	}
}

void TopicInfoList::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, time); break;
		case 1: vnl::from_string(_str, topics); break;
	}
}

void TopicInfoList::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, time); break;
		case 1: vnl::write(_out, topics); break;
		default: _out.putNull();
	}
}

void TopicInfoList::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, time); break;
		case 1: vnl::read(_in, topics); break;
	}
}


} // namespace
} // namespace
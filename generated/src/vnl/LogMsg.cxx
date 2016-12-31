
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/LogMsg.hxx>
#include <vnl/Type.hxx>

namespace vnl {

const uint32_t LogMsg::VNI_HASH;
const uint32_t LogMsg::NUM_FIELDS;

LogMsg* LogMsg::create() {
	return vnl::create<LogMsg>();
}

LogMsg* LogMsg::clone() const {
	return vnl::clone<LogMsg>(*this);
}

void LogMsg::destroy() {
	this->LogMsg::~LogMsg();
	return vnl::internal::global_pool_->push_back(this, sizeof(LogMsg));
}

void LogMsg::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
	_out.putHash(0x15364763); vnl::write(_out, level);
	_out.putHash(0x85aba286); vnl::write(_out, src_mac);
	_out.putHash(0x5190a58c); vnl::write(_out, domain);
	_out.putHash(0xf68c6937); vnl::write(_out, topic);
	_out.putHash(0xf7a74926); vnl::write(_out, msg);
}

void LogMsg::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			case 0x15364763: vnl::read(_in, level); break;
			case 0x85aba286: vnl::read(_in, src_mac); break;
			case 0x5190a58c: vnl::read(_in, domain); break;
			case 0xf68c6937: vnl::read(_in, topic); break;
			case 0xf7a74926: vnl::read(_in, msg); break;
			default: _in.skip();
		}
	}
}

int LogMsg::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x15364763: return 0;
		case 0x85aba286: return 1;
		case 0x5190a58c: return 2;
		case 0xf68c6937: return 3;
		case 0xf7a74926: return 4;
		default: return -1;
	}
}

const char* LogMsg::get_field_name(int _index) const {
	switch(_index) {
		case 0: return "level";
		case 1: return "src_mac";
		case 2: return "domain";
		case 3: return "topic";
		case 4: return "msg";
		default: return 0;
	}
}

void LogMsg::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, level); break;
		case 1: vnl::to_string(_str, src_mac); break;
		case 2: vnl::to_string(_str, domain); break;
		case 3: vnl::to_string(_str, topic); break;
		case 4: vnl::to_string(_str, msg); break;
	}
}

void LogMsg::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, level); break;
		case 1: vnl::from_string(_str, src_mac); break;
		case 2: vnl::from_string(_str, domain); break;
		case 3: vnl::from_string(_str, topic); break;
		case 4: vnl::from_string(_str, msg); break;
	}
}

void LogMsg::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, level); break;
		case 1: vnl::write(_out, src_mac); break;
		case 2: vnl::write(_out, domain); break;
		case 3: vnl::write(_out, topic); break;
		case 4: vnl::write(_out, msg); break;
		default: _out.putNull();
	}
}

void LogMsg::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, level); break;
		case 1: vnl::read(_in, src_mac); break;
		case 2: vnl::read(_in, domain); break;
		case 3: vnl::read(_in, topic); break;
		case 4: vnl::read(_in, msg); break;
	}
}


} // namespace

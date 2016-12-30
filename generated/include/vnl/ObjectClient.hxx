
#ifndef INCLUDE_VNI_GENERATED_vnl_Object_CLIENT_HXX_
#define INCLUDE_VNI_GENERATED_vnl_Object_CLIENT_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Array.h>
#include <vnl/Hash32.h>
#include <vnl/Map.h>
#include <vnl/Shutdown.hxx>
#include <vnl/String.h>
#include <vnl/Topic.hxx>

#include <vnl/Client.h>


namespace vnl {

class ObjectClient : public vnl::Client {
public:
	class Writer {
	public:
		Writer(vnl::io::TypeOutput& _out, bool _top_level = false) 
			:	_out(_out), _top_level(_top_level)
		{
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_BEGIN);
				_out.putHash(0x430e9bb0);
			}
		}
		~Writer() {
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_END);
			}
		}
		void set_config(const vnl::Hash32& name, const vnl::String& value) {
			_out.putEntry(VNL_IO_CALL, 2);
			_out.putHash(0x34266241);
			vnl::write(_out, name);
			vnl::write(_out, value);
		}
		void get_subscriptions() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x77258735);
		}
		void exit() {
			_out.putEntry(VNL_IO_CALL, 0);
			_out.putHash(0xe8592f85);
		}
		void get_config_map() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x1b85d99);
		}
		void get_config(const vnl::Hash32& name) {
			_out.putEntry(VNL_IO_CONST_CALL, 1);
			_out.putHash(0x9abb388d);
			vnl::write(_out, name);
		}
		void set_vnl_log_level(int32_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x482df535);
			vnl::write(_out, _value);
		}
		void set_vnl_max_num_pending(int32_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0xc30f0945);
			vnl::write(_out, _value);
		}
		void get_vnl_log_level() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x482df535);
		}
		void get_vnl_max_num_pending() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0xc30f0945);
		}
	protected:
		vnl::io::TypeOutput& _out;
		bool _top_level;
	};
	
	ObjectClient() {}
	
	ObjectClient(const ObjectClient& other) {
		vnl::Client::set_address(other.vnl::Client::get_address());
	}
	
	ObjectClient(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
	}
	
	ObjectClient& operator=(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
		return *this;
	}
	
	void set_config(const vnl::Hash32& name, const vnl::String& value) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_config(name, value);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	vnl::Array<vnl::Topic > get_subscriptions() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_subscriptions();
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CONST_CALL);
		vnl::Array<vnl::Topic > _result;
		if(_pkt) {
			vnl::read(_in, _result);
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
		return _result;
	}
	
	void exit() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.exit();
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	vnl::Map<vnl::String, vnl::String > get_config_map() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_config_map();
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CONST_CALL);
		vnl::Map<vnl::String, vnl::String > _result;
		if(_pkt) {
			vnl::read(_in, _result);
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
		return _result;
	}
	
	vnl::String get_config(const vnl::Hash32& name) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_config(name);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CONST_CALL);
		vnl::String _result;
		if(_pkt) {
			vnl::read(_in, _result);
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
		return _result;
	}
	
	void set_vnl_log_level(int32_t vnl_log_level) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_vnl_log_level(vnl_log_level);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_vnl_max_num_pending(int32_t vnl_max_num_pending) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_vnl_max_num_pending(vnl_max_num_pending);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	int32_t get_vnl_log_level() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_vnl_log_level();
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CONST_CALL);
		int32_t _result;
		if(_pkt) {
			vnl::read(_in, _result);
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
		return _result;
	}
	
	int32_t get_vnl_max_num_pending() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_vnl_max_num_pending();
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CONST_CALL);
		int32_t _result;
		if(_pkt) {
			vnl::read(_in, _result);
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
		return _result;
	}
	
};


} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_Object_CLIENT_HXX_
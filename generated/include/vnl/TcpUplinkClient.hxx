
#ifndef INCLUDE_VNI_GENERATED_vnl_TcpUplink_CLIENT_HXX_
#define INCLUDE_VNI_GENERATED_vnl_TcpUplink_CLIENT_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/String.h>
#include <vnl/Topic.hxx>

#include <vnl/ObjectClient.hxx>


namespace vnl {

class TcpUplinkClient : public vnl::ObjectClient {
public:
	class Writer : public vnl::ObjectClient::Writer {
	public:
		Writer(vnl::io::TypeOutput& _out, bool _top_level = false) 
			:	vnl::ObjectClient::Writer(_out, false),
				_out(_out), _top_level(_top_level)
		{
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_BEGIN);
				_out.putHash(0xb681b3d8);
			}
		}
		~Writer() {
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_END);
			}
		}
		void publish(const vnl::Topic& topic) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x983c173d);
			vnl::write(_out, topic);
		}
		void subscribe(const vnl::Topic& topic) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0xdc322bca);
			vnl::write(_out, topic);
		}
		void subscribe(const vnl::String& domain, const vnl::String& topic) {
			_out.putEntry(VNL_IO_CALL, 2);
			_out.putHash(0x3bb5d48f);
			vnl::write(_out, domain);
			vnl::write(_out, topic);
		}
		void publish(const vnl::String& domain, const vnl::String& topic) {
			_out.putEntry(VNL_IO_CALL, 2);
			_out.putHash(0x7fbbe878);
			vnl::write(_out, domain);
			vnl::write(_out, topic);
		}
		void set_send_timeout(int32_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x279e615d);
			vnl::write(_out, _value);
		}
		void set_error_interval(int32_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x55f7671e);
			vnl::write(_out, _value);
		}
		void set_are_connected(bool _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x1f5839d4);
			vnl::write(_out, _value);
		}
		void set_num_drop(int64_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x5e24337a);
			vnl::write(_out, _value);
		}
		void get_send_timeout() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x279e615d);
		}
		void get_error_interval() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x55f7671e);
		}
		void get_are_connected() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x1f5839d4);
		}
		void get_num_drop() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x5e24337a);
		}
	protected:
		vnl::io::TypeOutput& _out;
		bool _top_level;
	};
	
	TcpUplinkClient() {}
	
	TcpUplinkClient(const TcpUplinkClient& other) {
		vnl::Client::set_address(other.vnl::Client::get_address());
	}
	
	TcpUplinkClient(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
	}
	
	TcpUplinkClient& operator=(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
		return *this;
	}
	
	void publish(const vnl::Topic& topic) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.publish(topic);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void subscribe(const vnl::Topic& topic) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.subscribe(topic);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void subscribe(const vnl::String& domain, const vnl::String& topic) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.subscribe(domain, topic);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void publish(const vnl::String& domain, const vnl::String& topic) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.publish(domain, topic);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_send_timeout(int32_t send_timeout) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_send_timeout(send_timeout);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_error_interval(int32_t error_interval) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_error_interval(error_interval);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_are_connected(bool are_connected) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_are_connected(are_connected);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_num_drop(int64_t num_drop) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_num_drop(num_drop);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	int32_t get_send_timeout() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_send_timeout();
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
	
	int32_t get_error_interval() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_error_interval();
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
	
	bool get_are_connected() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_are_connected();
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CONST_CALL);
		bool _result;
		if(_pkt) {
			vnl::read(_in, _result);
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
		return _result;
	}
	
	int64_t get_num_drop() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_num_drop();
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CONST_CALL);
		int64_t _result;
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

#endif // INCLUDE_VNI_GENERATED_vnl_TcpUplink_CLIENT_HXX_

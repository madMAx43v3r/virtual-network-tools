
#ifndef INCLUDE_VNI_GENERATED_vnl_UdpServer_CLIENT_HXX_
#define INCLUDE_VNI_GENERATED_vnl_UdpServer_CLIENT_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/String.h>

#include <vnl/ObjectClient.hxx>


namespace vnl {

class UdpServerClient : public vnl::ObjectClient {
public:
	class Writer : public vnl::ObjectClient::Writer {
	public:
		Writer(vnl::io::TypeOutput& _out, bool _top_level = false) 
			:	vnl::ObjectClient::Writer(_out, false),
				_out(_out), _top_level(_top_level)
		{
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_BEGIN);
				_out.putHash(0xce08dbee);
			}
		}
		~Writer() {
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_END);
			}
		}
		void unsubscribe(const vnl::String& domain, const vnl::String& topic) {
			_out.putEntry(VNL_IO_CALL, 2);
			_out.putHash(0xed7dfb37);
			vnl::write(_out, domain);
			vnl::write(_out, topic);
		}
		void unsubscribe_all() {
			_out.putEntry(VNL_IO_CALL, 0);
			_out.putHash(0x14ffa0f1);
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
		void unpublish(const vnl::String& domain, const vnl::String& topic) {
			_out.putEntry(VNL_IO_CALL, 2);
			_out.putHash(0xc7428d8c);
			vnl::write(_out, domain);
			vnl::write(_out, topic);
		}
		void set_port(int32_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x13e7a893);
			vnl::write(_out, _value);
		}
		void set_send_buffer_size(int32_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0xfd6e8f27);
			vnl::write(_out, _value);
		}
		void set_receive_buffer_size(int32_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x998b692c);
			vnl::write(_out, _value);
		}
		void get_port() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x13e7a893);
		}
		void get_send_buffer_size() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0xfd6e8f27);
		}
		void get_receive_buffer_size() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x998b692c);
		}
	protected:
		vnl::io::TypeOutput& _out;
		bool _top_level;
	};
	
	UdpServerClient() {}
	
	UdpServerClient(const UdpServerClient& other) {
		vnl::Client::set_address(other.vnl::Client::get_address());
	}
	
	UdpServerClient(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
	}
	
	UdpServerClient& operator=(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
		return *this;
	}
	
	void unsubscribe(const vnl::String& domain, const vnl::String& topic) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.unsubscribe(domain, topic);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void unsubscribe_all() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.unsubscribe_all();
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
	
	void unpublish(const vnl::String& domain, const vnl::String& topic) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.unpublish(domain, topic);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_port(int32_t port) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_port(port);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_send_buffer_size(int32_t send_buffer_size) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_send_buffer_size(send_buffer_size);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_receive_buffer_size(int32_t receive_buffer_size) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_receive_buffer_size(receive_buffer_size);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	int32_t get_port() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_port();
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
	
	int32_t get_send_buffer_size() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_send_buffer_size();
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
	
	int32_t get_receive_buffer_size() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_receive_buffer_size();
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

#endif // INCLUDE_VNI_GENERATED_vnl_UdpServer_CLIENT_HXX_

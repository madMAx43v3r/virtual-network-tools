
#ifndef INCLUDE_VNI_GENERATED_vnl_Uplink_CLIENT_HXX_
#define INCLUDE_VNI_GENERATED_vnl_Uplink_CLIENT_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/String.h>

#include <vnl/Client.h>


namespace vnl {

class UplinkClient : public vnl::Client {
public:
	class Writer {
	public:
		Writer(vnl::io::TypeOutput& _out, bool _top_level = false) 
			:	_out(_out), _top_level(_top_level)
		{
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_BEGIN);
				_out.putHash(0x8d07ab7a);
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
	protected:
		vnl::io::TypeOutput& _out;
		bool _top_level;
	};
	
	UplinkClient() {}
	
	UplinkClient(const UplinkClient& other) {
		vnl::Client::set_address(other.vnl::Client::get_address());
	}
	
	UplinkClient(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
	}
	
	UplinkClient& operator=(const vnl::Address& addr) {
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
	
};


} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_Uplink_CLIENT_HXX_

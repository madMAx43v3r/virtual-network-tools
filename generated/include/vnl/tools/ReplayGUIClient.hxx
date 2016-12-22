
#ifndef INCLUDE_VNI_GENERATED_vnl_tools_ReplayGUI_CLIENT_HXX_
#define INCLUDE_VNI_GENERATED_vnl_tools_ReplayGUI_CLIENT_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/String.h>
#include <vnl/Topic.hxx>
#include <vnl/info/PlayerStatus.hxx>

#include <vnl/ObjectClient.hxx>


namespace vnl {
namespace tools {

class ReplayGUIClient : public vnl::ObjectClient {
public:
	class Writer : public vnl::ObjectClient::Writer {
	public:
		Writer(vnl::io::TypeOutput& _out, bool _top_level = false) 
			:	vnl::ObjectClient::Writer(_out, false),
				_out(_out), _top_level(_top_level)
		{
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_BEGIN);
				_out.putHash(0x49f8783);
			}
		}
		~Writer() {
			if(_top_level) {
				_out.putEntry(VNL_IO_INTERFACE, VNL_IO_END);
			}
		}
		void set_target_host(const vnl::String& _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x97e08f18);
			vnl::write(_out, _value);
		}
		void set_target_port(int32_t _value) {
			_out.putEntry(VNL_IO_CALL, 1);
			_out.putHash(0x579173b0);
			vnl::write(_out, _value);
		}
		void get_target_host() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x97e08f18);
		}
		void get_target_port() {
			_out.putEntry(VNL_IO_CONST_CALL, 0);
			_out.putHash(0x579173b0);
		}
	protected:
		vnl::io::TypeOutput& _out;
		bool _top_level;
	};
	
	ReplayGUIClient() {}
	
	ReplayGUIClient(const ReplayGUIClient& other) {
		vnl::Client::set_address(other.vnl::Client::get_address());
	}
	
	ReplayGUIClient(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
	}
	
	ReplayGUIClient& operator=(const vnl::Address& addr) {
		vnl::Client::set_address(addr);
		return *this;
	}
	
	void set_target_host(const vnl::String& target_host) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_target_host(target_host);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	void set_target_port(int32_t target_port) {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.set_target_port(target_port);
		}
		vnl::Packet* _pkt = _call(vnl::Frame::CALL);
		if(_pkt) {
			_pkt->ack();
		} else {
			throw vnl::IOException();
		}
	}
	
	vnl::String get_target_host() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_target_host();
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
	
	int32_t get_target_port() {
		_buf.wrap(_data);
		{
			Writer _wr(_out);
			_wr.get_target_port();
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
} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_tools_ReplayGUI_CLIENT_HXX_

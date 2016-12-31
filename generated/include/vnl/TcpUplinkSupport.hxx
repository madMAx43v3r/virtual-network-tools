
#ifndef INCLUDE_VNI_GENERATED_vnl_TcpUplinkBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_TcpUplinkBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Object.h>
#include <vnl/String.h>
#include <vnl/Topic.hxx>
#include <vnl/info/RemoteInfo.hxx>

#include <vnl/Type.hxx>


namespace vnl {

class TcpUplinkBase : public vnl::Object {
public:
	static const uint32_t VNI_HASH = 0xb681b3d8;
	static const uint32_t NUM_FIELDS = 6;
	
	typedef vnl::Object Super;
	
	
	int32_t send_timeout;
	int32_t error_interval;
	bool are_connected;
	int64_t num_drop;
	
	TcpUplinkBase(const vnl::String& domain_, const vnl::String& topic_)
		:	vnl::Object::Object(domain_, topic_)
	{
		send_timeout = -1;
		error_interval = 1000000;
		are_connected = false;
		num_drop = 0;
		vnl::read_config(domain_, topic_, "send_timeout", send_timeout);
		vnl::read_config(domain_, topic_, "error_interval", error_interval);
		vnl::read_config(domain_, topic_, "are_connected", are_connected);
		vnl::read_config(domain_, topic_, "num_drop", num_drop);
	}
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.TcpUplink"; }
	
	virtual int get_num_fields() const { return NUM_FIELDS; }
	virtual int get_field_index(vnl::Hash32 _hash) const;
	virtual const char* get_field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
protected:
	virtual void handle(const vnl::info::RemoteInfo& sample, const vnl::Packet& packet) { handle(sample); }
	virtual void handle(const vnl::info::RemoteInfo& sample, vnl::Basic* input) { handle(sample); }
	virtual void handle(const vnl::info::RemoteInfo& sample) {}
	virtual void unsubscribe(const vnl::String& domain, const vnl::String& topic) = 0;
	virtual void handle(const vnl::Topic& sample, const vnl::Packet& packet) { handle(sample); }
	virtual void handle(const vnl::Topic& sample, vnl::Basic* input) { handle(sample); }
	virtual void handle(const vnl::Topic& sample) {}
	virtual void unsubscribe_all() = 0;
	virtual void subscribe(const vnl::String& domain, const vnl::String& topic) = 0;
	virtual void reset() = 0;
	virtual void publish(const vnl::String& domain, const vnl::String& topic) = 0;
	virtual vnl::info::RemoteInfo get_remote_info() const = 0;
	virtual void unpublish(const vnl::String& domain, const vnl::String& topic) = 0;
	
	virtual bool vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args);
	virtual bool vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Packet* _packet);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Basic* _input);
	
	template<class W>
	void write_fields(W& _writer) const {
		_writer.set_vnl_log_level(vnl_log_level);
		_writer.set_vnl_max_num_pending(vnl_max_num_pending);
		_writer.set_send_timeout(send_timeout);
		_writer.set_error_interval(error_interval);
		_writer.set_are_connected(are_connected);
		_writer.set_num_drop(num_drop);
	}
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_TcpUplinkBase_HXX_

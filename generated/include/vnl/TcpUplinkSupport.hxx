
#ifndef INCLUDE_VNI_GENERATED_vnl_TcpUplinkBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_TcpUplinkBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Address.h>
#include <vnl/Object.h>
#include <vnl/String.h>
#include <vnl/Topic.hxx>
#include <vnl/info/RemoteInfo.hxx>

#include <vnl/Type.hxx>


namespace vnl {

class TcpUplinkBase : public vnl::Object {
public:
	static const uint32_t VNI_HASH = 0xb681b3d8;
	static const uint32_t NUM_FIELDS = 10;
	
	typedef vnl::Object Super;
	
	
	int32_t error_interval;
	bool are_connected;
	int64_t num_read;
	int64_t num_write;
	int64_t num_flush;
	int64_t num_bytes_read;
	int64_t num_bytes_write;
	
	TcpUplinkBase(const vnl::String& domain_, const vnl::String& topic_)
		:	vnl::Object::Object(domain_, topic_)
	{
		error_interval = 1000000;
		are_connected = false;
		num_read = 0;
		num_write = 0;
		num_flush = 0;
		num_bytes_read = 0;
		num_bytes_write = 0;
		vnl::read_config(domain_, topic_, "error_interval", error_interval);
		vnl::read_config(domain_, topic_, "are_connected", are_connected);
		vnl::read_config(domain_, topic_, "num_read", num_read);
		vnl::read_config(domain_, topic_, "num_write", num_write);
		vnl::read_config(domain_, topic_, "num_flush", num_flush);
		vnl::read_config(domain_, topic_, "num_bytes_read", num_bytes_read);
		vnl::read_config(domain_, topic_, "num_bytes_write", num_bytes_write);
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
	virtual void get_field(int _index, vnl::Var& _var) const;
	virtual void set_field(int _index, const vnl::Var& _var);
	
protected:
	virtual void publish(const vnl::Address& addr) = 0;
	virtual void handle(const vnl::info::RemoteInfo& sample, const vnl::Packet& packet) { handle(sample); }
	virtual void handle(const vnl::info::RemoteInfo& sample, vnl::Basic* input) { handle(sample); }
	virtual void handle(const vnl::info::RemoteInfo& sample) {}
	virtual void unsubscribe(const vnl::String& domain, const vnl::String& topic) = 0;
	virtual void handle(const vnl::Topic& sample, const vnl::Packet& packet) { handle(sample); }
	virtual void handle(const vnl::Topic& sample, vnl::Basic* input) { handle(sample); }
	virtual void handle(const vnl::Topic& sample) {}
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
		_writer.set_vnl_msg_timeout(vnl_msg_timeout);
		_writer.set_vnl_heartbeat_interval(vnl_heartbeat_interval);
		_writer.set_error_interval(error_interval);
		_writer.set_are_connected(are_connected);
		_writer.set_num_read(num_read);
		_writer.set_num_write(num_write);
		_writer.set_num_flush(num_flush);
		_writer.set_num_bytes_read(num_bytes_read);
		_writer.set_num_bytes_write(num_bytes_write);
	}
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_TcpUplinkBase_HXX_

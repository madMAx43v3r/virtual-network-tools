
#ifndef INCLUDE_VNI_GENERATED_vnl_TcpServerBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_TcpServerBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Address.h>
#include <vnl/Array.h>
#include <vnl/Object.h>
#include <vnl/String.h>
#include <vnl/Topic.hxx>

#include <vnl/Type.hxx>


namespace vnl {

class TcpServerBase : public vnl::Object {
public:
	static const uint32_t VNI_HASH = 0x2d8a645f;
	static const uint32_t NUM_FIELDS = 11;
	
	typedef vnl::Object Super;
	
	
	int32_t port;
	int32_t error_interval;
	vnl::Array<vnl::Topic > export_topics;
	int32_t accept_queue;
	bool tcp_keepalive;
	bool tcp_nodelay;
	int32_t send_buffer_size;
	int32_t receive_buffer_size;
	
	TcpServerBase(const vnl::String& domain_, const vnl::String& topic_);
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.TcpServer"; }
	
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
	virtual void unsubscribe(const vnl::String& domain, const vnl::String& topic) = 0;
	virtual void subscribe(const vnl::String& domain, const vnl::String& topic) = 0;
	virtual void publish(const vnl::String& domain, const vnl::String& topic) = 0;
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
		_writer.set_port(port);
		_writer.set_error_interval(error_interval);
		_writer.set_export_topics(export_topics);
		_writer.set_accept_queue(accept_queue);
		_writer.set_tcp_keepalive(tcp_keepalive);
		_writer.set_tcp_nodelay(tcp_nodelay);
		_writer.set_send_buffer_size(send_buffer_size);
		_writer.set_receive_buffer_size(receive_buffer_size);
	}
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_TcpServerBase_HXX_

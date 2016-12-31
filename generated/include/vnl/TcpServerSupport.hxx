
#ifndef INCLUDE_VNI_GENERATED_vnl_TcpServerBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_TcpServerBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

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
	int32_t send_timeout;
	bool tcp_keepalive;
	bool tcp_nodelay;
	int32_t send_buffer_size;
	int32_t receive_buffer_size;
	
	TcpServerBase(const vnl::String& domain_, const vnl::String& topic_)
		:	vnl::Object::Object(domain_, topic_)
	{
		port = 8916;
		error_interval = 1000000;
		accept_queue = 10;
		send_timeout = -1;
		tcp_keepalive = true;
		tcp_nodelay = true;
		send_buffer_size = 1048576;
		receive_buffer_size = 1048576;
		vnl::read_config(domain_, topic_, "port", port);
		vnl::read_config(domain_, topic_, "error_interval", error_interval);
		vnl::read_config(domain_, topic_, "export_topics", export_topics);
		vnl::read_config(domain_, topic_, "accept_queue", accept_queue);
		vnl::read_config(domain_, topic_, "send_timeout", send_timeout);
		vnl::read_config(domain_, topic_, "tcp_keepalive", tcp_keepalive);
		vnl::read_config(domain_, topic_, "tcp_nodelay", tcp_nodelay);
		vnl::read_config(domain_, topic_, "send_buffer_size", send_buffer_size);
		vnl::read_config(domain_, topic_, "receive_buffer_size", receive_buffer_size);
	}
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.TcpServer"; }
	
	virtual int get_num_fields() const { return NUM_FIELDS; }
	virtual int get_field_index(vnl::Hash32 _hash) const;
	virtual const char* get_field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
protected:
	virtual void unsubscribe(const vnl::String& domain, const vnl::String& topic) = 0;
	virtual void unsubscribe_all() = 0;
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
		_writer.set_vnl_max_num_pending(vnl_max_num_pending);
		_writer.set_port(port);
		_writer.set_error_interval(error_interval);
		_writer.set_export_topics(export_topics);
		_writer.set_accept_queue(accept_queue);
		_writer.set_send_timeout(send_timeout);
		_writer.set_tcp_keepalive(tcp_keepalive);
		_writer.set_tcp_nodelay(tcp_nodelay);
		_writer.set_send_buffer_size(send_buffer_size);
		_writer.set_receive_buffer_size(receive_buffer_size);
	}
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_TcpServerBase_HXX_

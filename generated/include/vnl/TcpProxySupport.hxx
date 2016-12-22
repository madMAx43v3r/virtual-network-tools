
#ifndef INCLUDE_VNI_GENERATED_vnl_TcpProxyBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_TcpProxyBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/TcpUplink.h>

#include <vnl/Type.hxx>


namespace vnl {

class TcpProxyBase : public vnl::TcpUplink {
public:
	static const uint32_t VNI_HASH = 0x33de85dc;
	static const uint32_t NUM_FIELDS = 6;
	
	typedef vnl::TcpUplink Super;
	
	
	
	TcpProxyBase(const vnl::String& domain_, const vnl::String& topic_)
		:	vnl::TcpUplink::TcpUplink(domain_, topic_)
	{
	}
	
	virtual uint32_t vni_hash() const { return VNI_HASH; }
	virtual const char* type_name() const { return "vnl.TcpProxy"; }
	
	virtual int num_fields() const { return NUM_FIELDS; }
	virtual int field_index(vnl::Hash32 _hash) const;
	virtual const char* field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
protected:
	
	virtual bool vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args);
	virtual bool vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Packet* _packet);
	
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

#endif // INCLUDE_VNI_GENERATED_vnl_TcpProxyBase_HXX_

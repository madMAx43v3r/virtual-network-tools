
#ifndef INCLUDE_VNI_GENERATED_vnl_ObjectBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_ObjectBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Hash32.h>
#include <vnl/Interface.h>
#include <vnl/Map.h>
#include <vnl/Shutdown.hxx>
#include <vnl/String.h>

#include <vnl/Type.hxx>


namespace vnl {

class ObjectBase : public vnl::Interface {
public:
	static const uint32_t VNI_HASH = 0x430e9bb0;
	static const uint32_t NUM_FIELDS = 3;
	
	typedef vnl::Interface Super;
	
	static const int32_t ERROR = 1;
	static const int32_t WARN = 2;
	static const int32_t INFO = 3;
	static const int32_t DEBUG = 4;
	
	int32_t vnl_log_level;
	int32_t vnl_msg_timeout;
	int32_t vnl_heartbeat_interval;
	
	ObjectBase(const vnl::String& domain_, const vnl::String& topic_);
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.Object"; }
	
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
	virtual vnl::String get_private_domain() const = 0;
	virtual void set_config(const vnl::Hash32& name, const vnl::String& value) = 0;
	virtual void handle(const vnl::Shutdown& event, const vnl::Packet& packet) { handle(event); }
	virtual void handle(const vnl::Shutdown& event, vnl::Basic* input) { handle(event); }
	virtual void handle(const vnl::Shutdown& event) {}
	virtual void exit() = 0;
	virtual vnl::Map<vnl::String, vnl::String > get_config_map() const = 0;
	virtual vnl::String get_config(const vnl::Hash32& name) const = 0;
	
	virtual bool vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args);
	virtual bool vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Packet* _packet);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Basic* _input);
	
	template<class W>
	void write_fields(W& _writer) const {
		_writer.set_vnl_log_level(vnl_log_level);
		_writer.set_vnl_msg_timeout(vnl_msg_timeout);
		_writer.set_vnl_heartbeat_interval(vnl_heartbeat_interval);
	}
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_ObjectBase_HXX_

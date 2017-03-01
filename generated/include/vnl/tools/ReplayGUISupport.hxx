
#ifndef INCLUDE_VNI_GENERATED_vnl_tools_ReplayGUIBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_tools_ReplayGUIBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Object.h>
#include <vnl/String.h>
#include <vnl/Topic.hxx>
#include <vnl/info/PlayerStatus.hxx>

#include <vnl/Type.hxx>


namespace vnl {
namespace tools {

class ReplayGUIBase : public vnl::Object {
public:
	static const uint32_t VNI_HASH = 0x49f8783;
	static const uint32_t NUM_FIELDS = 5;
	
	typedef vnl::Object Super;
	
	
	vnl::String target_host;
	int32_t target_port;
	
	ReplayGUIBase(const vnl::String& domain_, const vnl::String& topic_);
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.tools.ReplayGUI"; }
	
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
	virtual void handle(const vnl::Topic& topic, const vnl::Packet& packet) { handle(topic); }
	virtual void handle(const vnl::Topic& topic, vnl::Basic* input) { handle(topic); }
	virtual void handle(const vnl::Topic& topic) {}
	virtual void handle(const vnl::info::PlayerStatus& status, const vnl::Packet& packet) { handle(status); }
	virtual void handle(const vnl::info::PlayerStatus& status, vnl::Basic* input) { handle(status); }
	virtual void handle(const vnl::info::PlayerStatus& status) {}
	
	virtual bool vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args);
	virtual bool vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Packet* _packet);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Basic* _input);
	
	template<class W>
	void write_fields(W& _writer) const {
		_writer.set_vnl_log_level(vnl_log_level);
		_writer.set_vnl_msg_timeout(vnl_msg_timeout);
		_writer.set_vnl_heartbeat_interval(vnl_heartbeat_interval);
		_writer.set_target_host(target_host);
		_writer.set_target_port(target_port);
	}
	
};

} // namespace
} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_tools_ReplayGUIBase_HXX_

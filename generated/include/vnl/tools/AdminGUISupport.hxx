
#ifndef INCLUDE_VNI_GENERATED_vnl_tools_AdminGUIBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_tools_AdminGUIBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/LogMsg.hxx>
#include <vnl/Object.h>
#include <vnl/String.h>
#include <vnl/info/RemoteInfo.hxx>
#include <vnl/info/TopicInfoList.hxx>

#include <vnl/Type.hxx>


namespace vnl {
namespace tools {

class AdminGUIBase : public vnl::Object {
public:
	static const uint32_t VNI_HASH = 0x1d8bdfc8;
	static const uint32_t NUM_FIELDS = 7;
	
	typedef vnl::Object Super;
	
	
	vnl::String target_host;
	int32_t target_port;
	int32_t interval;
	int32_t max_topic_interval;
	int32_t max_array_size;
	
	AdminGUIBase(const vnl::String& domain_, const vnl::String& topic_)
		:	vnl::Object::Object(domain_, topic_)
	{
		target_host = "localhost";
		target_port = 8916;
		interval = 2000;
		max_topic_interval = 200000;
		max_array_size = 100;
		vnl::read_config(domain_, topic_, "target_host", target_host);
		vnl::read_config(domain_, topic_, "target_port", target_port);
		vnl::read_config(domain_, topic_, "interval", interval);
		vnl::read_config(domain_, topic_, "max_topic_interval", max_topic_interval);
		vnl::read_config(domain_, topic_, "max_array_size", max_array_size);
	}
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.tools.AdminGUI"; }
	
	virtual int get_num_fields() const { return NUM_FIELDS; }
	virtual int get_field_index(vnl::Hash32 _hash) const;
	virtual const char* get_field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
protected:
	virtual void handle(const vnl::info::TopicInfoList& sample, const vnl::Packet& packet) { handle(sample); }
	virtual void handle(const vnl::info::TopicInfoList& sample, vnl::Basic* input) { handle(sample); }
	virtual void handle(const vnl::info::TopicInfoList& sample) {}
	virtual void handle(const vnl::info::RemoteInfo& sample, const vnl::Packet& packet) { handle(sample); }
	virtual void handle(const vnl::info::RemoteInfo& sample, vnl::Basic* input) { handle(sample); }
	virtual void handle(const vnl::info::RemoteInfo& sample) {}
	virtual void handle(const vnl::LogMsg& sample, const vnl::Packet& packet) { handle(sample); }
	virtual void handle(const vnl::LogMsg& sample, vnl::Basic* input) { handle(sample); }
	virtual void handle(const vnl::LogMsg& sample) {}
	
	virtual bool vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args);
	virtual bool vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Packet* _packet);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Basic* _input);
	
	template<class W>
	void write_fields(W& _writer) const {
		_writer.set_vnl_log_level(vnl_log_level);
		_writer.set_vnl_max_num_pending(vnl_max_num_pending);
		_writer.set_target_host(target_host);
		_writer.set_target_port(target_port);
		_writer.set_interval(interval);
		_writer.set_max_topic_interval(max_topic_interval);
		_writer.set_max_array_size(max_array_size);
	}
	
};

} // namespace
} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_tools_AdminGUIBase_HXX_

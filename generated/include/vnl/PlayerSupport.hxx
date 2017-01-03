
#ifndef INCLUDE_VNI_GENERATED_vnl_PlayerBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_PlayerBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Array.h>
#include <vnl/Object.h>
#include <vnl/String.h>
#include <vnl/Topic.hxx>
#include <vnl/info/PlayerStatus.hxx>

#include <vnl/Type.hxx>


namespace vnl {

class PlayerBase : public vnl::Object {
public:
	static const uint32_t VNI_HASH = 0xe536451b;
	static const uint32_t NUM_FIELDS = 10;
	
	typedef vnl::Object Super;
	
	
	vnl::String filename;
	vnl::Array<vnl::String > domain_blacklist;
	vnl::Array<vnl::Topic > topic_blacklist;
	bool autostart;
	bool autoloop;
	bool autoshutdown;
	int32_t interval;
	
	PlayerBase(const vnl::String& domain_, const vnl::String& topic_)
		:	vnl::Object::Object(domain_, topic_)
	{
		filename = "rec-???.dat";
		autostart = false;
		autoloop = false;
		autoshutdown = false;
		interval = 200000;
		vnl::read_config(domain_, topic_, "filename", filename);
		vnl::read_config(domain_, topic_, "domain_blacklist", domain_blacklist);
		vnl::read_config(domain_, topic_, "topic_blacklist", topic_blacklist);
		vnl::read_config(domain_, topic_, "autostart", autostart);
		vnl::read_config(domain_, topic_, "autoloop", autoloop);
		vnl::read_config(domain_, topic_, "autoshutdown", autoshutdown);
		vnl::read_config(domain_, topic_, "interval", interval);
	}
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.Player"; }
	
	virtual int get_num_fields() const { return NUM_FIELDS; }
	virtual int get_field_index(vnl::Hash32 _hash) const;
	virtual const char* get_field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
protected:
	virtual void pause() = 0;
	virtual void seek_rel(float pos) = 0;
	virtual void stop() = 0;
	virtual void reset() = 0;
	virtual vnl::Array<vnl::Topic > get_topics() const = 0;
	virtual void scan() = 0;
	virtual void play() = 0;
	virtual vnl::info::PlayerStatus get_status() const = 0;
	virtual void seek(int64_t time) = 0;
	virtual void open(const vnl::String& file) = 0;
	
	virtual bool vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args);
	virtual bool vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Packet* _packet);
	virtual bool handle_switch(vnl::Value* _sample, vnl::Basic* _input);
	
	template<class W>
	void write_fields(W& _writer) const {
		_writer.set_vnl_log_level(vnl_log_level);
		_writer.set_vnl_msg_timeout(vnl_msg_timeout);
		_writer.set_vnl_heartbeat_interval(vnl_heartbeat_interval);
		_writer.set_filename(filename);
		_writer.set_domain_blacklist(domain_blacklist);
		_writer.set_topic_blacklist(topic_blacklist);
		_writer.set_autostart(autostart);
		_writer.set_autoloop(autoloop);
		_writer.set_autoshutdown(autoshutdown);
		_writer.set_interval(interval);
	}
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_PlayerBase_HXX_

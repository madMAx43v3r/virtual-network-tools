
#ifndef INCLUDE_VNI_GENERATED_vnl_DatabaseBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_DatabaseBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Object.h>
#include <vnl/String.h>

#include <vnl/Type.hxx>


namespace vnl {

class DatabaseBase : public vnl::Object {
public:
	static const uint32_t VNI_HASH = 0x1a20923;
	static const uint32_t NUM_FIELDS = 4;
	
	typedef vnl::Object Super;
	
	
	vnl::String filename;
	bool ignore_errors;
	
	DatabaseBase(const vnl::String& domain_, const vnl::String& topic_)
		:	vnl::Object::Object(domain_, topic_)
	{
		filename = "database.dat";
		ignore_errors = false;
		vnl::read_config(domain_, topic_, "filename", filename);
		vnl::read_config(domain_, topic_, "ignore_errors", ignore_errors);
	}
	
	virtual uint32_t vni_hash() const { return VNI_HASH; }
	virtual const char* type_name() const { return "vnl.Database"; }
	
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
		_writer.set_filename(filename);
		_writer.set_ignore_errors(ignore_errors);
	}
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_DatabaseBase_HXX_

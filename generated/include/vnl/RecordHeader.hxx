
#ifndef INCLUDE_VNI_GENERATED_vnl_RecordHeader_HXX_
#define INCLUDE_VNI_GENERATED_vnl_RecordHeader_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Array.h>
#include <vnl/Topic.hxx>
#include <vnl/Value.hxx>

#include <vnl/Type.hxx>


namespace vnl {

class RecordHeader : public vnl::Value {
public:
	static const uint32_t VNI_HASH = 0xc10cd56c;
	static const uint32_t NUM_FIELDS = 7;
	
	
	int32_t version;
	int32_t header_size;
	bool have_type_info;
	int64_t num_samples;
	int64_t begin_time;
	int64_t end_time;
	vnl::Array<vnl::Topic > topics;
	
	RecordHeader();
	
	static RecordHeader* create();
	static RecordHeader* create(vnl::Hash32 hash);
	virtual RecordHeader* clone() const;
	virtual bool is_assignable(vnl::Hash32 hash);
	virtual bool assign(const vnl::Value& _value);
	virtual void raise() const { throw *this; }
	virtual void destroy();
	
	virtual void serialize(vnl::io::TypeOutput& _out) const;
	virtual void deserialize(vnl::io::TypeInput& _in, int _size);
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.RecordHeader"; }
	
	virtual int get_type_size() const { return sizeof(RecordHeader); }
	virtual int get_num_fields() const { return NUM_FIELDS; }
	virtual int get_field_index(vnl::Hash32 _hash) const;
	virtual const char* get_field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	virtual void get_field(int _index, vnl::Var& _var) const;
	virtual void set_field(int _index, const vnl::Var& _var);
	
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_RecordHeader_HXX_

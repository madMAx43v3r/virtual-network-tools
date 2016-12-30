
#ifndef INCLUDE_VNI_GENERATED_vnl_NoSuchMethodException_HXX_
#define INCLUDE_VNI_GENERATED_vnl_NoSuchMethodException_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/IOException.hxx>

#include <vnl/Type.hxx>


namespace vnl {

class NoSuchMethodException : public vnl::IOException {
public:
	static const uint32_t VNI_HASH = 0x69a97186;
	static const uint32_t NUM_FIELDS = 0;
	
	
	
	NoSuchMethodException() {
	}
	
	static NoSuchMethodException* create();
	virtual NoSuchMethodException* clone() const;
	virtual void raise() const { throw *this; }
	virtual void destroy();
	
	virtual void serialize(vnl::io::TypeOutput& _out) const;
	virtual void deserialize(vnl::io::TypeInput& _in, int _size);
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.NoSuchMethodException"; }
	
	virtual int get_type_size() const { return sizeof(NoSuchMethodException); }
	virtual int get_num_fields() const { return NUM_FIELDS; }
	virtual int get_field_index(vnl::Hash32 _hash) const;
	virtual const char* get_field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_NoSuchMethodException_HXX_

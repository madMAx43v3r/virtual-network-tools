
#ifndef INCLUDE_VNI_GENERATED_vnl_DuplicateKeyException_HXX_
#define INCLUDE_VNI_GENERATED_vnl_DuplicateKeyException_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/IOException.hxx>

#include <vnl/Type.hxx>


namespace vnl {

class DuplicateKeyException : public vnl::IOException {
public:
	static const uint32_t VNI_HASH = 0x7e6aa525;
	static const uint32_t NUM_FIELDS = 0;
	
	
	
	DuplicateKeyException() {
	}
	
	static DuplicateKeyException* create();
	virtual DuplicateKeyException* clone() const;
	virtual void raise() const { throw *this; }
	virtual void destroy();
	
	virtual void serialize(vnl::io::TypeOutput& _out) const;
	virtual void deserialize(vnl::io::TypeInput& _in, int _size);
	
	virtual uint32_t vni_hash() const { return VNI_HASH; }
	virtual const char* type_name() const { return "vnl.DuplicateKeyException"; }
	
	virtual int type_size() const { return sizeof(DuplicateKeyException); }
	virtual int num_fields() const { return NUM_FIELDS; }
	virtual int field_index(vnl::Hash32 _hash) const;
	virtual const char* field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_DuplicateKeyException_HXX_

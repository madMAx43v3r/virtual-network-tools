
#ifndef INCLUDE_VNI_GENERATED_vnl_UplinkBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_UplinkBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Interface.h>
#include <vnl/String.h>
#include <vnl/Topic.hxx>

#include <vnl/Type.hxx>


namespace vnl {

class UplinkBase : public vnl::Interface {
public:
	static const uint32_t VNI_HASH = 0x8d07ab7a;
	static const uint32_t NUM_FIELDS = 0;
	
	typedef vnl::Interface Super;
	
	
	
	UplinkBase() {
	}
	
	virtual uint32_t vni_hash() const { return VNI_HASH; }
	virtual const char* type_name() const { return "vnl.Uplink"; }
	
	virtual int num_fields() const { return NUM_FIELDS; }
	virtual int field_index(vnl::Hash32 _hash) const;
	virtual const char* field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
protected:
	virtual void publish(const vnl::Topic& topic) = 0;
	virtual void subscribe(const vnl::Topic& topic) = 0;
	virtual void subscribe(const vnl::String& domain, const vnl::String& topic) = 0;
	virtual void publish(const vnl::String& domain, const vnl::String& topic) = 0;
	
	virtual bool vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args);
	virtual bool vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out);
	
	template<class W>
	void write_fields(W& _writer) const {
	}
	
};

} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_UplinkBase_HXX_

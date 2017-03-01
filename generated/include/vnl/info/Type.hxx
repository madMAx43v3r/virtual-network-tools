
#ifndef INCLUDE_VNI_GENERATED_vnl_info_Type_HXX_
#define INCLUDE_VNI_GENERATED_vnl_info_Type_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Hash32.h>
#include <vnl/SList.h>
#include <vnl/String.h>
#include <vnl/Value.hxx>
#include <vnl/info/Field.hxx>
#include <vnl/info/Method.hxx>
#include <vnl/info/TypeName.hxx>

#include <vnl/Type.hxx>


namespace vnl {
namespace info {

class Type : public vnl::Value {
public:
	static const uint32_t VNI_HASH = 0xbde99c40;
	static const uint32_t NUM_FIELDS = 11;
	
	
	vnl::Hash32 hash;
	vnl::String name;
	vnl::info::TypeName super;
	bool is_struct;
	bool is_class;
	bool is_enum;
	bool is_interface;
	bool is_object;
	vnl::SList<vnl::info::Field > fields;
	vnl::SList<vnl::info::Method > methods;
	vnl::SList<vnl::String > symbols;
	
	Type();
	
	static Type* create();
	static Type* create(vnl::Hash32 hash);
	virtual Type* clone() const;
	virtual bool is_assignable(vnl::Hash32 hash);
	virtual bool assign(const vnl::Value& _value);
	virtual void raise() const { throw *this; }
	virtual void destroy();
	
	virtual void serialize(vnl::io::TypeOutput& _out) const;
	virtual void deserialize(vnl::io::TypeInput& _in, int _size);
	
	virtual uint32_t get_vni_hash() const { return VNI_HASH; }
	virtual const char* get_type_name() const { return "vnl.info.Type"; }
	
	virtual int get_type_size() const { return sizeof(Type); }
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
} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_info_Type_HXX_

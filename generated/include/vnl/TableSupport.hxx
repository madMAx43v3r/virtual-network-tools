
#ifndef INCLUDE_VNI_GENERATED_vnl_TableBase_HXX_
#define INCLUDE_VNI_GENERATED_vnl_TableBase_HXX_

// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Array.h>
#include <vnl/Binary.h>
#include <vnl/Database.h>
#include <vnl/Hash32.h>
#include <vnl/Hash64.h>

#include <vnl/Type.hxx>


namespace vnl {

template<class T>
class TableBase : public vnl::Database {
public:
	static const uint32_t VNI_HASH = 0xbd71f457;
	static const uint32_t NUM_FIELDS = 4;
	
	typedef vnl::Database Super;
	
	
	
	TableBase(const vnl::String& domain_, const vnl::String& topic_)
		:	vnl::Database::Database(domain_, topic_)
	{
	}
	
	virtual uint32_t vni_hash() const { return VNI_HASH; }
	virtual const char* type_name() const { return "vnl.Table"; }
	
	virtual int num_fields() const { return NUM_FIELDS; }
	virtual int field_index(vnl::Hash32 _hash) const;
	virtual const char* field_name(int _index) const;
	virtual void get_field(int _index, vnl::String& _str) const;
	virtual void set_field(int _index, const vnl::String& _str);
	virtual void get_field(int _index, vnl::io::TypeOutput& _out) const;
	virtual void set_field(int _index, vnl::io::TypeInput& _in);
	
protected:
	virtual void update(const vnl::Hash64& id, const vnl::Hash32& field_name, const vnl::Binary& value) = 0;
	virtual void insert(const T& row) = 0;
	virtual T get(const vnl::Hash64& id) const = 0;
	virtual vnl::Array<T > get_all(const vnl::Array<vnl::Hash64 >& ids) const = 0;
	virtual void remove(const vnl::Hash64& id) = 0;
	
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

template<class T>
const uint32_t TableBase<T>::VNI_HASH;
template<class T>
const uint32_t TableBase<T>::NUM_FIELDS;

template<class T>
int TableBase<T>::field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		case 0x482df535: return 0;
		case 0xc30f0945: return 1;
		case 0xb60d3446: return 2;
		case 0x2d7512a8: return 3;
		default: return -1;
	}
}

template<class T>
const char* TableBase<T>::field_name(int _index) const {
	switch(_index) {
		case 0: return "vnl_log_level";
		case 1: return "vnl_max_num_pending";
		case 2: return "filename";
		case 3: return "ignore_errors";
		default: return 0;
	}
}

template<class T>
void TableBase<T>::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
		case 0: vnl::to_string(_str, vnl_log_level); break;
		case 1: vnl::to_string(_str, vnl_max_num_pending); break;
		case 2: vnl::to_string(_str, filename); break;
		case 3: vnl::to_string(_str, ignore_errors); break;
		default: _str << "{}";
	}
}

template<class T>
void TableBase<T>::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
		case 0: vnl::from_string(_str, vnl_log_level); break;
		case 1: vnl::from_string(_str, vnl_max_num_pending); break;
		case 2: vnl::from_string(_str, filename); break;
		case 3: vnl::from_string(_str, ignore_errors); break;
	}
}

template<class T>
void TableBase<T>::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		case 0: vnl::write(_out, vnl_log_level); break;
		case 1: vnl::write(_out, vnl_max_num_pending); break;
		case 2: vnl::write(_out, filename); break;
		case 3: vnl::write(_out, ignore_errors); break;
		default: _out.putNull();
	}
}

template<class T>
void TableBase<T>::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
		case 0: vnl::read(_in, vnl_log_level); break;
		case 1: vnl::read(_in, vnl_max_num_pending); break;
		case 2: vnl::read(_in, filename); break;
		case 3: vnl::read(_in, ignore_errors); break;
	}
}

template<class T>
bool TableBase<T>::vni_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args) {
	switch(_hash) {
	case 0x299f3f53: 
		switch(_num_args) {
			case 1: {
				vnl::Hash64 id;
				vnl::read(_in, id);
				if(!_in.error()) {
					remove(id);
					return true;
				}
			}
			break;
		}
		break;
	case 0x62d971d5: 
		switch(_num_args) {
			case 3: {
				vnl::Hash64 id;
				vnl::read(_in, id);
				vnl::Hash32 field_name;
				vnl::read(_in, field_name);
				vnl::Binary value;
				vnl::read(_in, value);
				if(!_in.error()) {
					update(id, field_name, value);
					return true;
				}
			}
			break;
		}
		break;
	case 0xaeb0fe60: 
		switch(_num_args) {
			case 1: {
				T row;
				vnl::read(_in, row);
				if(!_in.error()) {
					insert(row);
					return true;
				}
			}
			break;
		}
		break;
	}
	return Super::vni_call(_in, _hash, _num_args);
}

template<class T>
bool TableBase<T>::vni_const_call(vnl::io::TypeInput& _in, uint32_t _hash, int _num_args, vnl::io::TypeOutput& _out) {
	switch(_hash) {
	case 0x1b0fad1f: 
		switch(_num_args) {
			case 1: {
				vnl::Hash64 id;
				vnl::read(_in, id);
				if(!_in.error()) {
					T _res = get(id);
					vnl::write(_out, _res);
					return true;
				}
			}
			break;
		}
		break;
	case 0x6726988c: 
		switch(_num_args) {
			case 1: {
				vnl::Array<vnl::Hash64 > ids;
				vnl::read(_in, ids);
				if(!_in.error()) {
					vnl::Array<T > _res = get_all(ids);
					vnl::write(_out, _res);
					return true;
				}
			}
			break;
		}
		break;
	}
	return Super::vni_const_call(_in, _hash, _num_args, _out);
}

template<class T>
bool TableBase<T>::handle_switch(vnl::Value* _sample, vnl::Packet* _packet) {
	switch(_sample->vni_hash()) {
	}
	return Super::handle_switch(_sample, _packet);
}


} // namespace

#endif // INCLUDE_VNI_GENERATED_vnl_TableBase_HXX_

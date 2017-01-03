
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/Value.hxx>
#include <vnl/Type.hxx>
#include <vnl/Announce.hxx>
#include <vnl/DuplicateKeyException.hxx>
#include <vnl/Exception.hxx>
#include <vnl/Exit.hxx>
#include <vnl/Header.hxx>
#include <vnl/Heartbeat.hxx>
#include <vnl/IOException.hxx>
#include <vnl/Instance.hxx>
#include <vnl/LogMsg.hxx>
#include <vnl/NoSuchFieldException.hxx>
#include <vnl/NoSuchKeyException.hxx>
#include <vnl/NoSuchMethodException.hxx>
#include <vnl/RecordHeader.hxx>
#include <vnl/RecordValue.hxx>
#include <vnl/Shutdown.hxx>
#include <vnl/TimeoutException.hxx>
#include <vnl/Topic.hxx>
#include <vnl/info/Field.hxx>
#include <vnl/info/Method.hxx>
#include <vnl/info/ObjectInfo.hxx>
#include <vnl/info/Parameter.hxx>
#include <vnl/info/PlayerStatus.hxx>
#include <vnl/info/RemoteInfo.hxx>
#include <vnl/info/TopicInfo.hxx>
#include <vnl/info/TopicInfoList.hxx>
#include <vnl/info/Type.hxx>

namespace vnl {

vnl::Value* create(vnl::Hash32 hash) {
	switch(hash) {
		case 0x417d65c7: return vnl::create<vnl::Announce>();
		case 0x7e6aa525: return vnl::create<vnl::DuplicateKeyException>();
		case 0xbe87903d: return vnl::create<vnl::Exception>();
		case 0x3bd088b0: return vnl::create<vnl::Exit>();
		case 0x52740af4: return vnl::create<vnl::Header>();
		case 0xa262a675: return vnl::create<vnl::Heartbeat>();
		case 0xabd5ff87: return vnl::create<vnl::IOException>();
		case 0x67d48190: return vnl::create<vnl::Instance>();
		case 0x9df3e6f5: return vnl::create<vnl::LogMsg>();
		case 0xd7988e27: return vnl::create<vnl::NoSuchFieldException>();
		case 0xd8d131ca: return vnl::create<vnl::NoSuchKeyException>();
		case 0x69a97186: return vnl::create<vnl::NoSuchMethodException>();
		case 0xc10cd56c: return vnl::create<vnl::RecordHeader>();
		case 0x1cdb1920: return vnl::create<vnl::RecordValue>();
		case 0xcdc22e1f: return vnl::create<vnl::Shutdown>();
		case 0x8c528f1: return vnl::create<vnl::TimeoutException>();
		case 0xddc3d187: return vnl::create<vnl::Topic>();
		case 0xd52524d4: return vnl::create<vnl::info::Field>();
		case 0x1b510753: return vnl::create<vnl::info::Method>();
		case 0x6400b0b3: return vnl::create<vnl::info::ObjectInfo>();
		case 0xf5e3f3b6: return vnl::create<vnl::info::Parameter>();
		case 0xf9baa92e: return vnl::create<vnl::info::PlayerStatus>();
		case 0x7aa64297: return vnl::create<vnl::info::RemoteInfo>();
		case 0x1e3eb783: return vnl::create<vnl::info::TopicInfo>();
		case 0xdc558ad: return vnl::create<vnl::info::TopicInfoList>();
		case 0xbde99c40: return vnl::create<vnl::info::Type>();
		default: return 0;
	}
}

vnl::Array<vnl::String> get_class_names() {
	vnl::Array<vnl::String> res;
	res.push_back("vnl.Announce");
	res.push_back("vnl.DuplicateKeyException");
	res.push_back("vnl.Exception");
	res.push_back("vnl.Exit");
	res.push_back("vnl.Header");
	res.push_back("vnl.Heartbeat");
	res.push_back("vnl.IOException");
	res.push_back("vnl.Instance");
	res.push_back("vnl.LogMsg");
	res.push_back("vnl.NoSuchFieldException");
	res.push_back("vnl.NoSuchKeyException");
	res.push_back("vnl.NoSuchMethodException");
	res.push_back("vnl.RecordHeader");
	res.push_back("vnl.RecordValue");
	res.push_back("vnl.Shutdown");
	res.push_back("vnl.TimeoutException");
	res.push_back("vnl.Topic");
	res.push_back("vnl.info.Field");
	res.push_back("vnl.info.Method");
	res.push_back("vnl.info.ObjectInfo");
	res.push_back("vnl.info.Parameter");
	res.push_back("vnl.info.PlayerStatus");
	res.push_back("vnl.info.RemoteInfo");
	res.push_back("vnl.info.TopicInfo");
	res.push_back("vnl.info.TopicInfoList");
	res.push_back("vnl.info.Type");
	return res;
}

vnl::Map<vnl::Hash32, vnl::info::Type> get_type_info() {
	vnl::Map<vnl::Hash32, vnl::info::Type> res;
	{
		vnl::info::Type& info = res["vnl.Announce"];
		info.hash = 0x417d65c7;
		info.name = "vnl.Announce";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xfb4f2b4;
			field.name = "instance";
			field.type = "vnl.Instance";
		}
	}
	{
		vnl::info::Type& info = res["vnl.DuplicateKeyException"];
		info.hash = 0x7e6aa525;
		info.name = "vnl.DuplicateKeyException";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.Exception"];
		info.hash = 0xbe87903d;
		info.name = "vnl.Exception";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.Exit"];
		info.hash = 0x3bd088b0;
		info.name = "vnl.Exit";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.Header"];
		info.hash = 0x52740af4;
		info.name = "vnl.Header";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xd27ee4a0;
			field.name = "src_topic";
			field.type = "vnl.Topic";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xaaf981a0;
			field.name = "dst_topic";
			field.type = "vnl.Topic";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x85aba286;
			field.name = "src_mac";
			field.type = "vnl.Hash64";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x6ed7c747;
			field.name = "send_time";
			field.type = "long";
		}
	}
	{
		vnl::info::Type& info = res["vnl.Heartbeat"];
		info.hash = 0xa262a675;
		info.name = "vnl.Heartbeat";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x85aba286;
			field.name = "src_mac";
			field.type = "vnl.Hash64";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xd129c896;
			field.name = "interval";
			field.type = "int";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xcaacc145;
			field.name = "info";
			field.type = "vnl.info.ObjectInfo";
		}
	}
	{
		vnl::info::Type& info = res["vnl.IOException"];
		info.hash = 0xabd5ff87;
		info.name = "vnl.IOException";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.Instance"];
		info.hash = 0x67d48190;
		info.name = "vnl.Instance";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x5fa779df;
			field.name = "type";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x5190a58c;
			field.name = "domain";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xf68c6937;
			field.name = "topic";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x85aba286;
			field.name = "src_mac";
			field.type = "vnl.Hash64";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xb5065ea4;
			field.name = "heartbeat_interval";
			field.type = "int";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x57723c04;
			field.name = "last_heartbeat";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xa2fb771f;
			field.name = "is_alive";
			field.type = "bool";
		}
	}
	{
		vnl::info::Type& info = res["vnl.LogMsg"];
		info.hash = 0x9df3e6f5;
		info.name = "vnl.LogMsg";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x15364763;
			field.name = "level";
			field.type = "int";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x85aba286;
			field.name = "src_mac";
			field.type = "vnl.Hash64";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xf7a74926;
			field.name = "msg";
			field.type = "vnl.String";
		}
	}
	{
		vnl::info::Type& info = res["vnl.NoSuchFieldException"];
		info.hash = 0xd7988e27;
		info.name = "vnl.NoSuchFieldException";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.NoSuchKeyException"];
		info.hash = 0xd8d131ca;
		info.name = "vnl.NoSuchKeyException";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.NoSuchMethodException"];
		info.hash = 0x69a97186;
		info.name = "vnl.NoSuchMethodException";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.RecordHeader"];
		info.hash = 0xc10cd56c;
		info.name = "vnl.RecordHeader";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x55c30e99;
			field.name = "version";
			field.type = "int";
			vnl::to_string(field.value, 1);
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xd7a7ecc4;
			field.name = "header_size";
			field.type = "int";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x5ee0fae3;
			field.name = "num_samples";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x9c1b758e;
			field.name = "begin_time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x28517039;
			field.name = "end_time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x22dd6aa2;
			field.name = "topics";
			field.type = "vnl.Array";
		}
	}
	{
		vnl::info::Type& info = res["vnl.RecordValue"];
		info.hash = 0x1cdb1920;
		info.name = "vnl.RecordValue";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xaf3e4ff0;
			field.name = "time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x5190a58c;
			field.name = "domain";
			field.type = "vnl.Hash64";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xf68c6937;
			field.name = "topic";
			field.type = "vnl.Hash64";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x278de0d5;
			field.name = "header";
			field.type = "vnl.Pointer";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xd6f81d18;
			field.name = "value";
			field.type = "vnl.Pointer";
		}
	}
	{
		vnl::info::Type& info = res["vnl.Shutdown"];
		info.hash = 0xcdc22e1f;
		info.name = "vnl.Shutdown";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.TimeoutException"];
		info.hash = 0x8c528f1;
		info.name = "vnl.TimeoutException";
		info.is_struct = true;
		info.is_class = true;
	}
	{
		vnl::info::Type& info = res["vnl.Topic"];
		info.hash = 0xddc3d187;
		info.name = "vnl.Topic";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x5190a58c;
			field.name = "domain";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x539b7130;
			field.name = "name";
			field.type = "vnl.String";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.Field"];
		info.hash = 0xd52524d4;
		info.name = "vnl.info.Field";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xc114cc40;
			field.name = "hash";
			field.type = "vnl.Hash32";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x539b7130;
			field.name = "name";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xd6f81d18;
			field.name = "value";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x5fa779df;
			field.name = "type";
			field.type = "vnl.String";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.Method"];
		info.hash = 0x1b510753;
		info.name = "vnl.info.Method";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xc114cc40;
			field.name = "hash";
			field.type = "vnl.Hash32";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x539b7130;
			field.name = "name";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x5fa779df;
			field.name = "type";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x3f42b528;
			field.name = "params";
			field.type = "vnl.List";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.ObjectInfo"];
		info.hash = 0x6400b0b3;
		info.name = "vnl.info.ObjectInfo";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xaf3e4ff0;
			field.name = "time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xa5c8937c;
			field.name = "spawn_time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x7fd711c;
			field.name = "num_cycles";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xd6d6fb05;
			field.name = "num_msg_sent";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x7f0e60e;
			field.name = "num_msg_received";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xa065ff2d;
			field.name = "num_msg_dropped";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xce25565;
			field.name = "engine";
			field.type = "vnl.Hash64";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xa637ecaf;
			field.name = "input_channels";
			field.type = "vnl.Map";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x420d74;
			field.name = "output_channels";
			field.type = "vnl.Map";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.Parameter"];
		info.hash = 0xf5e3f3b6;
		info.name = "vnl.info.Parameter";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x539b7130;
			field.name = "name";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x5fa779df;
			field.name = "type";
			field.type = "vnl.String";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.PlayerStatus"];
		info.hash = 0xf9baa92e;
		info.name = "vnl.info.PlayerStatus";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xb60d3446;
			field.name = "filename";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x2c364d4d;
			field.name = "playing";
			field.type = "bool";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x38bdfa85;
			field.name = "error";
			field.type = "bool";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x9c1b758e;
			field.name = "begin_time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x28517039;
			field.name = "end_time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xec387c20;
			field.name = "current_time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x94c1d19e;
			field.name = "time_offset";
			field.type = "long";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.RemoteInfo"];
		info.hash = 0x7aa64297;
		info.name = "vnl.info.RemoteInfo";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x29243084;
			field.name = "domain_name";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x95fd810;
			field.name = "config_name";
			field.type = "vnl.String";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.TopicInfo"];
		info.hash = 0x1e3eb783;
		info.name = "vnl.info.TopicInfo";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xf68c6937;
			field.name = "topic";
			field.type = "vnl.Topic";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x8494c8d8;
			field.name = "publishers";
			field.type = "vnl.Map";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xfcc8b8eb;
			field.name = "subscribers";
			field.type = "vnl.Map";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xf56f7d1e;
			field.name = "send_counter";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xbafcf9f0;
			field.name = "receive_counter";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x50ad8a03;
			field.name = "first_time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x13c371be;
			field.name = "last_time";
			field.type = "long";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.TopicInfoList"];
		info.hash = 0xdc558ad;
		info.name = "vnl.info.TopicInfoList";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xaf3e4ff0;
			field.name = "time";
			field.type = "long";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x22dd6aa2;
			field.name = "topics";
			field.type = "vnl.Array";
		}
	}
	{
		vnl::info::Type& info = res["vnl.info.Type"];
		info.hash = 0xbde99c40;
		info.name = "vnl.info.Type";
		info.is_struct = true;
		info.is_class = true;
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xc114cc40;
			field.name = "hash";
			field.type = "vnl.Hash32";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x539b7130;
			field.name = "name";
			field.type = "vnl.String";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x72700701;
			field.name = "is_struct";
			field.type = "bool";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x674ff4e3;
			field.name = "is_class";
			field.type = "bool";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0xc1fa0e8c;
			field.name = "is_enum";
			field.type = "bool";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x3e98de28;
			field.name = "is_interface";
			field.type = "bool";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x4b4df272;
			field.name = "is_object";
			field.type = "bool";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x96d44ab3;
			field.name = "fields";
			field.type = "vnl.List";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x8457c8be;
			field.name = "methods";
			field.type = "vnl.List";
		}
		{
			vnl::info::Field& field = *info.fields.push_back();
			field.hash = 0x7cefe7cf;
			field.name = "symbols";
			field.type = "vnl.List";
		}
	}
	{
		vnl::info::Type& info = res["vnl.Enum"];
		info.hash = 0x5d6ea668;
		info.name = "vnl.Enum";
		info.is_enum = true;
	}
	return res;
}

const uint32_t Value::VNI_HASH;
const uint32_t Value::NUM_FIELDS;

Value* Value::create() {
	return vnl::create<Value>();
}

Value* Value::clone() const {
	return vnl::clone<Value>(*this);
}

void Value::destroy() {
	this->Value::~Value();
	return vnl::internal::global_pool_->push_back(this, sizeof(Value));
}

void Value::serialize(vnl::io::TypeOutput& _out) const {
	_out.putEntry(VNL_IO_CLASS, NUM_FIELDS);
	_out.putHash(VNI_HASH);
}

void Value::deserialize(vnl::io::TypeInput& _in, int _size) {
	for(int i = 0; i < _size && !_in.error(); ++i) {
		uint32_t _hash = 0;
		_in.getHash(_hash);
		switch(_hash) {
			default: _in.skip();
		}
	}
}

int Value::get_field_index(vnl::Hash32 _hash) const {
	switch(_hash) {
		default: return -1;
	}
}

const char* Value::get_field_name(int _index) const {
	switch(_index) {
		default: return 0;
	}
}

void Value::get_field(int _index, vnl::String& _str) const {
	switch(_index) {
	}
}

void Value::set_field(int _index, const vnl::String& _str) {
	switch(_index) {
	}
}

void Value::get_field(int _index, vnl::io::TypeOutput& _out) const {
	switch(_index) {
		default: _out.putNull();
	}
}

void Value::set_field(int _index, vnl::io::TypeInput& _in) {
	switch(_index) {
	}
}


} // namespace

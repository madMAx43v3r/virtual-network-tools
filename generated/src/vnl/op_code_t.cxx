
// AUTO GENERATED by virtual-network-interface codegen

#include <vnl/op_code_t.hxx>
#include <vnl/Type.hxx>
#include <vnl/Var.h>

namespace vnl {


op_code_t::op_code_t() {
}

const uint32_t op_code_t::NOOP;
const uint32_t op_code_t::MOV;
const uint32_t op_code_t::REF;
const uint32_t op_code_t::CMP;
const uint32_t op_code_t::ADD;
const uint32_t op_code_t::SUB;
const uint32_t op_code_t::MUL;
const uint32_t op_code_t::DIV;
const uint32_t op_code_t::MOD;
const uint32_t op_code_t::PUSH;
const uint32_t op_code_t::POP;
const uint32_t op_code_t::LOAD;
const uint32_t op_code_t::STORE;
const uint32_t op_code_t::PUSH_BACK;
const uint32_t op_code_t::PUSH_FRONT;
const uint32_t op_code_t::POP_BACK;
const uint32_t op_code_t::POP_FRONT;
const uint32_t op_code_t::SET;
const uint32_t op_code_t::GET;
const uint32_t op_code_t::ERASE;
const uint32_t op_code_t::JMP;
const uint32_t op_code_t::CALL;
const uint32_t op_code_t::RET;
const uint32_t op_code_t::READ;
const uint32_t op_code_t::WRITE;

void op_code_t::to_string_ex(vnl::String& str) const {
	str.push_back('"');
	switch(value) {
		case 0xddc2502d: str << "NOOP"; break;
		case 0x838be867: str << "MOV"; break;
		case 0xe67c57c5: str << "REF"; break;
		case 0x2ec5e872: str << "CMP"; break;
		case 0xe9e85174: str << "ADD"; break;
		case 0xa7b233f3: str << "SUB"; break;
		case 0x4f98c20: str << "MUL"; break;
		case 0x5350cdda: str << "DIV"; break;
		case 0x7af82e75: str << "MOD"; break;
		case 0x89652f06: str << "PUSH"; break;
		case 0x6c605d8f: str << "POP"; break;
		case 0x455eb8a3: str << "LOAD"; break;
		case 0xe2fbdba5: str << "STORE"; break;
		case 0x728e271a: str << "PUSH_BACK"; break;
		case 0x3dc1e640: str << "PUSH_FRONT"; break;
		case 0xb147a790: str << "POP_BACK"; break;
		case 0x6ddb3cbf: str << "POP_FRONT"; break;
		case 0x8e65fc1c: str << "SET"; break;
		case 0x8376aa8a: str << "GET"; break;
		case 0xe8106fb8: str << "ERASE"; break;
		case 0x9bf2f564: str << "JMP"; break;
		case 0x91caf30d: str << "CALL"; break;
		case 0x1f0f91d7: str << "RET"; break;
		case 0x139dda85: str << "READ"; break;
		case 0x4c9fd481: str << "WRITE"; break;
		default: str << "?";
	}
	str.push_back('"');
}


} // namespace

#include "../include/asmgen.h"
#include "../include/tokens.h"
#include "../include/lex.h"

AssemblyGen::AssemblyGen(const std::string& input) {
    this->data = input;
}
std::string handle_string(std::string input){
    std::string out ;
    for (int i =0;i<input.size();++i){
        switch (input[i]){
            case '\n':
                if (i == input.size()-1){
                    out += "10";
                    break;
                }
                if (i == 0){
                    out += "10,\"";
                    break;
                }
                
                out += "10,";
                break;
            case '\t':
                if (i == input.size()-1){
                    out += "9";
                    break;
                }
                if (i == 0){
                    out += "9,";
                    break;
                }
                
                out += "9,";
                break;
            case '\r':
                if (i==input.size()-1){
                    out += "13";
                    break;
                }
                if (i == 0){
                    out += "13,";
                    break;
                }
                
                out += "13,";
                break;
            default:
                if (i==input.size()-1){
                    out += "'";
                    out += input[i];
                    out += "'";
                    break;
                }
                if (i == 0){
                    out +="'";
                    out += input[i];
                    out +="',";
                    break;
                }
                
                out +=  "'";
                out += input[i];
                out += "',";
                break;
        }
    }
    return out;
}
std::string AssemblyGen::gen_asm(){
    std::string format = "format ELF64\n";
    std::string section_data = "section \".data\"\nmsg: db ";
    section_data += handle_string(this->data);
    section_data += "\n";
    std::string section_code = "section \".text\" executable\npublic _start\n_start:\n";
    section_code += "mov rax,1\n";
    section_code += "mov rdi,1\n";
    section_code += "mov rsi,msg\n";
    section_code += "mov rdx,"+std::to_string(this->data.size())+"\n";
    section_code += "syscall\n";
    section_code += "mov rax,60\nxor rdi,rdi\nsyscall\n";

    std::string code = format + section_code + section_data;
    return code;
    
}

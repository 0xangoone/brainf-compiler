#ifndef ASM_GEN_H
#define ASM_GEN_H
#include <iostream>
class AssemblyGen{
public:
    AssemblyGen(const std::string& input);
    std::string gen_asm();
    std::string data;
};
#endif

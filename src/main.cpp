#include "../include/lex.h"
#include "../include/get_strings.h"
#include "../include/asmgen.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <stdio.h>
int main(int argc,char* argv[]){
    std::string line;
    std::ifstream inp(argv[1]);
    std::string code;
    while (getline(inp, line)) {
        code += line + "\n";
    }

    std::unique_ptr<Lexer> lexer(new Lexer(code));
    std::vector<Tokens> tokens = lexer->make_tokens();
    std::unique_ptr<StringsGetter> strings_get(new StringsGetter(tokens));
    std::string s = strings_get->get_strings();

    std::unique_ptr<AssemblyGen> generator(new AssemblyGen(s));
    std::string assm = generator->gen_asm();

    std::ofstream asm_file("output.asm");
    asm_file << assm;
    asm_file.close();

    system("fasm main.asm");
    system("rm output.asm");


    return 0;
}

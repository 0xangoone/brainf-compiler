#ifndef LEX_H
#define LEX_H
#include <iostream>
#include <vector>
#include "../include/tokens.h"
class Lexer{
public:
    Lexer(const std::string& input);
    void next();
    std::vector<Tokens> make_tokens();
private:
    std::string input;
    int cur_pos;
    char cur_char;
};
#endif

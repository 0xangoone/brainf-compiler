#ifndef GET_STR_H
#define GET_STR_H
#include "../include/lex.h"
#include "../include/tokens.h"
#include <iostream>

class StringsGetter{
public:
    StringsGetter(const std::vector<Tokens>& input);
    std::string get_strings();
    void next();
private:
    std::vector<Tokens> input;
    int cur_pos;
    Tokens cur_token;
};

#endif

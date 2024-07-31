#include "../include/tokens.h"
#include "../include/lex.h"
#include <iostream>
#include <string>
#include <unordered_map>
Lexer::Lexer(const std::string& input) : input(input), cur_pos(0) {
    if (!input.empty()) {
        this->input = input;
        this->cur_char = this->input[this->cur_pos];
    } else {
        this->cur_char = '\0'; 
    }
}
std::vector<Tokens> Lexer::make_tokens(){
    std::vector<Tokens> out;

    std::unordered_map<char, Tokens> lexe_arr = {
        {'.', Tokens::put_char},
        {'>', Tokens::move_right},
        {'<', Tokens::move_left},
        {'+', Tokens::add_cur},
        {'-', Tokens::sub_cur},
        {'[',Tokens::rb},
        {']',Tokens::lb}
    };

    while ( this->cur_pos < this->input.size() ){
        if (lexe_arr.find(this->cur_char) != lexe_arr.end())  out.push_back(lexe_arr.at(this->cur_char));
        this->next();
    }
    return out;
}
void Lexer::next(){
    if ( this->cur_pos < this->input.size() ){
        this->cur_pos += 1;
        this->cur_char = this->input[this->cur_pos];
    }else{
        this->cur_char = '\0';
    }
}

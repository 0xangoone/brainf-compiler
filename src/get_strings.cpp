#include "../include/get_strings.h"
#include "../include/tokens.h"
#include <cstdlib>
#include <cstdio>
StringsGetter::StringsGetter(const std::vector<Tokens>& input) : input(input) , cur_pos(0){
    if (!input.empty()){
        this->input   = input;
        this->cur_pos = 0;
    }
    this->cur_token   = this->input[0];
}
std::string StringsGetter::get_strings(){
    std::string strings;
    unsigned char       *temp     = new unsigned char[6000];
    size_t      cur_ind  = 0;
    size_t      loop_ind = 0;
    while (this->cur_pos < this->input.size()){
        switch ( this->cur_token ){
            case Tokens::add_cur:
                ++temp[cur_ind];

                this->next();
                break;
            case Tokens::sub_cur:
                --temp[cur_ind];
                this->next();
                break;
            case Tokens::move_left:
                if (cur_ind <= 0){
                    std::cout << "buffer underflow"<<std::endl;
                    delete[] temp;
                    exit(1);
                }
                cur_ind--;
                this->next();
                break;
            case Tokens::move_right:
                if (cur_ind >= 6000){
                    std::cout << "out of range"<<std::endl;
                    delete[] temp;
                    exit(1);
                }
                cur_ind++;
                this->next();
                break;
            case Tokens::lb:
                if (temp[cur_ind] > 0){
                    this->cur_pos = loop_ind;
                }
                this->next();
                break;
            case Tokens::rb:
                loop_ind = this->cur_pos;
                this->next();
                break;
            case Tokens::put_char:
                strings += temp[cur_ind];
                this->next();
                break;
            default:
                this->next();
                break;
        }
    }
    delete[] temp;
    return strings;
}
void StringsGetter::next(){
    if (this->cur_pos < this->input.size()){
        this->cur_token = this->input[++cur_pos];
    }
}

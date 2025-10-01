#include"RPN.hpp"

int main(int ac, char **av){
    RPN arr;

    if(ac != 2){
        std::cerr<<"\033[31mError:\n   example:./RPN \"7 7 * 7 -\"\033[0m"<<std::endl;
        return 1;
    }
    for(int i = 0; av[1][i];i++){
        if(!strchr("0123456789+-*/ \t\n",av[1][i]))
        {
            std::cerr<<"\033[31mError:\n   only digits and +-*/ are acceptable\033[0m"<<std::endl;
            return 1;
        }
    }
    if(!arr.fill(av[1])){
        return 1;
    }
    arr.calculate();
}
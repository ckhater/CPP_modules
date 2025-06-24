#include"ScalarConverter.hpp"

int main(int ac, char **av){
    if(ac != 2){
        std::cerr<< "\033[31m./convert <value>\033[0m"<<std::endl;
        return(1);
    }
    ScalarConverter::convert(av[1]);
    return(0);
}
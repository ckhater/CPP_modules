#include"BitcoinExchange.hpp"

int main(int ac, char **av){
    if(ac != 2){
        std::cerr<<"\033[31mError:\n  ./btc input.txt\033[0m"<<std::endl;
        return 1;
    }
    try{
        BitcoinExchange btc;
        std::fstream file;
        file.open(av[1],std::fstream::in);
        if(!file.is_open())
            throw MyError("\033[31mError:\n  could not open file.\033[0m");
        btc.getprice(file);
        file.close();
    }
    catch(std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
        return 1 ;
    }
    return 0;
}
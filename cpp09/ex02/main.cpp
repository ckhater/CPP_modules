#include "PmergeMe.hpp"

int main(int ac, char **av){
    if(ac == 1){
        std::cerr<<"\033[31mError: ./PemerMe [12...125]\033[0m"<<std::endl;
        return 1;
    }
    PmergeMe pm;
    std::list<int> cp;
    long l;
    char    *rst;

    for(int i = 1; i < ac;i++){
        l = std::strtol(av[i],&rst,10);
        if(l < 0 || l > INT_MAX || *rst){
            std::cerr<<"\033[31mError: Accepts only different positive integer\033[0m"<<std::endl;
            return 1;
        }
        cp.push_back(static_cast<int> (l));
    }
    if(pm.getArgs(cp)){
        std::cerr<<"\033[31mError: Accepts only different positive integer\033[0m"<<std::endl;
        return 1;
    }
    pm.Pmergelist();
    pm.Pmergedeque();
}

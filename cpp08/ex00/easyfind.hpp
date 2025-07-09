#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include<vector>
#include<list>

class MyException: std::exception{
    public:
        const char *what() const throw(){
            return"\033[31mOppps!! value not found\033[0m";
        }
};

template<typename T> int easyfind(T cont, int i){
    typename T::iterator it = std::find(cont.begin(),cont.end(),i);
    if(it != cont.end())
        return(std::distance(cont.begin(),it));
    else 
        throw MyException();
}


#endif

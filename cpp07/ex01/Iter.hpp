#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>

template<typename T, typename T2> void iter(T *arr, int length, void (*f)(T2 &)) {
    for(int i = 0; i < length; i++){
        f(arr[i]);
    }
}

template<typename T> void print(T &n){
    std::cout<<n<<std::endl;
}

#endif
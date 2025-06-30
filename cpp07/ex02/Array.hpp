#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>
#include<climits>
#include<ctime>
#include<cstdlib>

template<class T>class Array{
    private:
        T* array;
        unsigned int lenght;
    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &arr);
        Array &operator=(Array const &arr);
        T &operator[](int n)const;
        // const T  &operator[](int n) const;
        ~Array(void);
        unsigned int size(void)const;
};
#include"Array.tpp"
#endif
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<stack>

template<typename T> class MutantStack : public std::stack<T> {
    public:
    MutantStack():std::stack<T>(){}
    MutantStack(const MutantStack &mt):std::stack<T>(mt){}
    MutantStack &operator=(const MutantStack &mt){
        std::stack<T>::operator=(mt);
        return *this;
    }
    ~MutantStack(){}
    typedef typename std::deque<T>::iterator iterator; 
    typename std::deque<T>::iterator begin() {
        return this->c.begin();
    }

    typename std::deque<T>::iterator end() {
        return this->c.end();
    }
};


#endif
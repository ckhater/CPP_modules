#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<stack>
#include<exception>
#include<cstring>
#include<sstream>

class RPN{
    private:
        std::stack<int> stc;
        std::string st;
        RPN(const RPN &rp);
        RPN &operator=(const RPN &rp);
    public:
        RPN(void);
        ~RPN(void);
        void    calculate();
        int     fill(std::string str);
};

#endif
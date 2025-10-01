#include "RPN.hpp"

RPN::RPN(void){
}

RPN::~RPN(void){
}

RPN &RPN::operator=(const RPN &rp){
    (void)rp;
    return *this;
}

void    RPN::calculate(){
    int n1;
    int n2;

    for(int i = 0; st[i]; i++){
        if(st[i] == '*'){
            if(stc.size() < 2){
                std::cerr<<"\033[31mError\033[0m"<<std::endl;
                return ;
            }
            n2 = stc.top();
            stc.pop();
            n1 = stc.top();
            stc.pop();
            stc.push(n1 * n2);
        }
        else if(st[i] == '/'){
            if(stc.size() < 2){
                std::cerr<<"\033[31mError\033[0m"<<std::endl;
                return ;
            }
            if(stc.top() == 0){
                std::cerr<<"\033[31mError:\n   devision by 0\033[0m"<<std::endl;
                return ;
            }
            n2 = stc.top();
            stc.pop();
            n1 = stc.top();
            stc.pop();
            stc.push(n1 / n2);

        }
        else if(st[i] == '+'){
            if(stc.size() < 2){
                std::cerr<<"\033[31mError\033[0m"<<std::endl;
                return ;
            }
            n2 = stc.top();
            stc.pop();
            n1 = stc.top();
            stc.pop();
            stc.push(n1 + n2);

        }
        else if(st[i] == '-'){
            if(stc.size() < 2){
                std::cerr<<"\033[31mError\033[0m"<<std::endl;
                return ;
            }
            n2 = stc.top();
            stc.pop();
            n1 = stc.top();
            stc.pop();
            stc.push(n1 - n2);

        }
        else
            stc.push(st[i] - 48);
    }
    if(stc.size() != 1){
        std::cerr<<"\033[31mError\033[0m"<<std::endl;
        return;
    }
    std::cout<<stc.top()<<std::endl;
}

int     RPN::fill(std::string str){
    std::string sp;
    std::string nl;
    std::string tb;

    std::stringstream ss(str);
    while(std::getline(ss,sp,' ')){
        std::stringstream nn(sp);
        while(std::getline(nn,nl,'\n')){
            std::stringstream tt(nl);
            while(std::getline(tt,tb,'\t')){
                if(tb.length() > 1){
                    std::cerr<<"\033[31mError:\n   only digits and + - * / are acceptable\033[0m"<<std::endl;
                    return 0;
                }
                st.push_back(tb[0]);
            }
        }
    }
    return 1 ;
}
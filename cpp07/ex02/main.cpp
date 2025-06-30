#include "Array.hpp"
#include <sstream>
int main()
{
    int s = 5;
    const Array<std::string>name(s);
    Array<std::string>copy_name(s);
    for(int i =0; i<s;i++){
        std::ostringstream oss;
        oss << i;
        copy_name[i] = "mimi" + oss.str();
    }
    for(int i =0; i<s;i++){

        std::cout<<copy_name[i]<<std::endl;
    }
    Array<std::string>tmp(copy_name); 
    copy_name = name;
    std::cout<<"**************"<<std::endl;
    for(int i =0; i<s;i++){
        std::cout<<tmp[i]<<std::endl;
        std::cout<<"||"<<copy_name[i]<<"||"<<std::endl;
    }
    try{
        tmp[-30];
        std::cout<<"success"<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
        try{
        tmp[42949];
        std::cout<<"success"<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return (0);
}
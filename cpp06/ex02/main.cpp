#include"Dynamic.hpp"

int main(){
    Base *p = generate();
    identify(p);
    std::cout<<"***************************\n";
    identify(*p);
    delete p;
}

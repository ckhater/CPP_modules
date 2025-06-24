#include"Serializer.hpp"

int main(){
    Data d;
    d.ft = true;
    d.i = 55;
    d.name = "cycy";
    d.p = & d.ft;

    std::cout<<"\033[31m"<<&d.ft<<"\033[0m"<<std::endl;
    Data *n;
    n = Serializer::deserialize( Serializer::serialize(&d));
    std::cout<<n->ft<<std::endl;
    std::cout<<n->name<<std::endl;
    std::cout<<n->i<<std::endl;
    std::cout<<n->p<<std::endl;
}
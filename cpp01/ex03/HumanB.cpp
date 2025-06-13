#include"HumanB.hpp"

HumanB::HumanB(std::string str){
    name = str;
    we = NULL;
}

HumanB::~HumanB(){

}

void HumanB::setWeapon(Weapon &w){
    we = &w;
}

void HumanB::attack(){
    if(we)
        std::cout<<name<<"  attacks with their "<<we->getType()<<std::endl;
    else
        std::cout<<name<<"  attacks with no weapon"<<std::endl;
}
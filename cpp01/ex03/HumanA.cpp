#include"HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon):name(str),we(weapon){

}

HumanA::~HumanA(){

}

void HumanA::attack(){
    std::cout<<name<<"  attacks with their "<<we.getType()<<std::endl;
}

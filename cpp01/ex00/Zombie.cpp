#include"Zombie.hpp"

Zombie::Zombie(std::string zombiename):name(zombiename){
    std::cout<<"the "<<name<<" created successfully"<<std::endl;
}

Zombie::~Zombie(){
    std::cout<<"The "<<name<<" is destructed"<<std::endl;
}

void    Zombie::announce(void){
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
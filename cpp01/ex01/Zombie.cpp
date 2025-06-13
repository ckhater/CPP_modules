#include"Zombie.hpp"

Zombie::Zombie(void){}
// Zombie::Zombie(std::string zombiename):name(zombiename){
//     // std::cout<<"the "<<name<<" created successfully"<<std::endl;
//     // std::cout<<"*******************"<<std::endl<<std::endl;
// }

Zombie::~Zombie(){
    std::cout<<std::endl<<"The "<<name<<" is destructed"<<std::endl;
}

void    Zombie::announce(void){
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
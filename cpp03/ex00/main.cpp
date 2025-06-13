#include"ClapTrap.hpp"

int main(){
    ClapTrap clp("tom");

    clp.attack("jerry");
    clp.beRepaired(5);
    clp.takeDamage(30);
    clp.beRepaired(50);
}

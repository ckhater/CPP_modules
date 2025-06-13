#include"ScavTrap.hpp"

int main()
{
    ScavTrap p("mimi");
 
    p.attack("riri");
    p.beRepaired(41);
    p.attack("riri");
    p.takeDamage(51);
    p.beRepaired(0);
    p.guardGate();
}

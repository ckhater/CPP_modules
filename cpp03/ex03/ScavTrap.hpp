#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include"ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    public:
        ScavTrap(void);
        ScavTrap(std::string n);
        ScavTrap &operator=(ScavTrap const &clp);
        ScavTrap(ScavTrap const &clp);
        ~ScavTrap(void);
        void attack(const std::string &n);
        void guardGate();


};

#endif
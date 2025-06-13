#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<iostream>

class ClapTrap{
    protected:
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;
    public:
        ClapTrap(void);
        ClapTrap(std::string n);
        ClapTrap &operator=(ClapTrap const &clp);
        ClapTrap(ClapTrap const &clp);
        ~ClapTrap(void);
        void beRepaired(unsigned int amount);
        void takeDamage(unsigned int amount);
        void attack(const std::string& target);

};

#endif
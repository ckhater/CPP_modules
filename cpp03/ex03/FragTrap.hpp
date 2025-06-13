#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include"ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
    public:
        FragTrap(void);
        FragTrap(std::string n);
        FragTrap(FragTrap const &frg);
        FragTrap &operator=(FragTrap const &frg);
        ~FragTrap(void);
        void highFivesGuys(void);
};

#endif
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include"HumanA.hpp"


class HumanB{
    private:
        std::string name;
        Weapon *we;
    public:
        HumanB(std::string str);
        ~HumanB();
        void setWeapon(Weapon &w);
        void attack();
};


#endif
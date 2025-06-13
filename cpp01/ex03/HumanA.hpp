#ifndef HUMANA_HPP
#define HUMANA_HPP

#include"Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon&  we;
    public:
        HumanA(std::string str,Weapon& weapon);
        ~HumanA();
        void attack();
};

#endif

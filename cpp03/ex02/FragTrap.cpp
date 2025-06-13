#include"FragTrap.hpp"

FragTrap::FragTrap(void){
    std::cout<< "FragTrap constructor called"<< std::endl;
}

FragTrap::FragTrap(std::string n){
    std::cout<< "FragTrap parametrized constructor called"<< std::endl;
    this->name = n;
    this->attack_damage = 30;
    this->hit_points = 100;
    this->energy_points = 100;
}

FragTrap::FragTrap(FragTrap const &frg):ClapTrap(frg){
    std::cout<< "FragTrap copy constructor called"<< std::endl;
    *this = frg;
}

FragTrap &FragTrap::operator=(FragTrap const &frg){
    std::cout<< "FragTrap copy assignement called"<< std::endl;
    this->name = frg.name;
    this->hit_points = frg.hit_points;
    this->energy_points = frg.energy_points;
    this->attack_damage = frg.attack_damage;
    return *this;
}

FragTrap::~FragTrap(void){
    std::cout<< "FragTrap destructor called"<< std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout<< "FragTrap gives you High Five ✋"<< std::endl;
}

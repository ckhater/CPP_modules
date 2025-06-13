#include"DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string n):ScavTrap(n), FragTrap(n){
    std::cout<< "DiamondTrap parametrized contructor called"<< std::endl;
    this->name = n;
    ClapTrap::name = n + "clap_name";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
};

DiamondTrap::~DiamondTrap(void){
    std::cout<< "DiamondTrap Destructor called"<< std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &dmn): ClapTrap(dmn), ScavTrap(dmn), FragTrap(dmn)
{
    std::cout<< "DiamondTrap copy contructor called"<< std::endl;
    *this = dmn;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &dmn)
{
    std::cout<< "DiamondTrap copy assignement called"<< std::endl;
    this->name = dmn.name;
    this->attack_damage = dmn.attack_damage;
    this->energy_points = dmn.energy_points;
    this->hit_points = dmn.hit_points;
    return *this;
}

void DiamondTrap::whoAmI(void){
    std::cout<< "DiamondTrap name is "<<this->name
             << " ClapTrap name is "<< ClapTrap::name<< std::endl;
}



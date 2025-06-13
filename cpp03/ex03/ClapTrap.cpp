#include"ClapTrap.hpp"

ClapTrap::ClapTrap(void){
   std::cout<< "ClapTrap contructor called"<< std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &clp){
   std::cout<< "ClapTrap copy assignement called"<< std::endl;
   this->name = clp.name;
   this->hit_points = clp.hit_points;
   this->attack_damage = clp.attack_damage;
   this->energy_points = clp.energy_points;
   return(*this);
}

ClapTrap::ClapTrap(std::string n)
{
   std::cout<< "ClapTrap parametrized Contructor called"<< std::endl;
   this->name = n;
   this->attack_damage = 0;
   this->energy_points = 10;
   this->hit_points = 10;
}

ClapTrap::ClapTrap(ClapTrap const &clp){
   std::cout<< "ClapTrap Copy contructor called"<<std::endl;
   *this = clp;
}

ClapTrap::~ClapTrap(void){
   std::cout<< "ClapTrap Destructor called"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
   if(this->energy_points > 0 && this->hit_points > 0)
   {
      this->hit_points += amount;
      this->energy_points--;
      std::cout<< "ClapTrap is repaired, "<< this->name<< " hit points is "
      << this->hit_points<< std::endl;
      return ;
   }
   std::cout<< "ClapTrap "<< this->name<< " is dead ☠️"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
   if(hit_points <= 0 || this->energy_points <= 0)
   {
      std::cout<< "ClapTrap "<< this->name<< " is dead ☠️"<< std::endl;
      return;
   }
   std::cout<< "ClapTrap "<< this->name<< " took "<< amount<<" damage 🗡"<<std::endl;
   this->hit_points -= amount;
}

void ClapTrap::attack(const std::string& target){
   if(this->energy_points <= 0 || this->hit_points <= 0)
   { 
      std::cout<< "ClapTrap "<< this->name<< " is dead ☠️"<< std::endl;
      return ;
   }
   std::cout<< "ClapTrap "<< this->name<< " attacks "<< target<< ", causing "
               << this->attack_damage<< " points of damage!"<< std::endl;
   this->energy_points--;         
}

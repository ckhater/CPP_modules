#include"Ice.hpp"

Ice::Ice():AMateria("ice"){
    std::cout<< "Ice constructor called 🥶"<< std::endl;
}

Ice::~Ice(){
    std::cout<< "Ice destructor called"<< std::endl;
}

Ice &Ice::operator=(Ice const &cr){
    this->type = cr.type;
    return *this;
}

Ice::Ice(Ice const &cr):AMateria(cr){
}

AMateria *Ice::clone()const{
    return new Ice();
}

void    Ice::use(ICharacter& target){
    std::cout<< "* shoots an ice bolt at*"<<target.getName()<< std::endl;
}
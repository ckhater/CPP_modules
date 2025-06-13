#include"Dog.hpp"

Dog::Dog(void){
	std::cout<< "Dog constructor called"<< std::endl;
	this->type = "Dog";
}

Dog::~Dog(void){
	std::cout<< "Dog destructor called"<< std::endl;
}

Dog::Dog(const Dog &dg):Animal(dg){
	std::cout<< "Dog copy constructor called"<< std::endl;
	*this = dg;
}

Dog	&Dog::operator=(const Dog &dg){
	std::cout<< "Dog copy assignement operator called"<< std::endl;
	this->type = dg.type;
	return *this;
}

void	Dog::makeSound(void)const{
	std::cout<< this->type<< " 🐶 woof woof"<< std::endl;
}


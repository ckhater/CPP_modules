#include"Dog.hpp"

Dog::Dog(void){
	std::cout<< "Dog constructor called"<< std::endl;
	this->type = "Dog";
	br = new(Brain);
}

Dog::~Dog(void){
	delete br;
	std::cout<< "Dog destructor called"<< std::endl;
}

Dog::Dog(const Dog &dg):Animal(dg){
	std::cout<< "Dog copy constructor called"<< std::endl;
	this->br = new Brain();
}

Dog	&Dog::operator=(const Dog &dg){
	std::cout<< "Dog copy assignement operator called"<< std::endl;
	this->type = dg.type;
	if(this != &dg)
	{
		delete this->br;
		this->br = new Brain(*dg.br);
	}
	return *this;
}

void	Dog::makeSound(void)const{
	std::cout<< this->type<< " 🐶 woof woof"<< std::endl;
}

void	Dog::setBrain(int i, std::string idea){
	br->setIdea(i, idea);
}

std::string Dog::getBrain(int i){
	return br->getIdea(i);
}

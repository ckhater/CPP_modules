#include"Animal.hpp"

Animal::Animal(void){
	std::cout<< "Animal constructor called"<< std::endl;
	this->type = "Animal";
}

Animal::~Animal(void){
	std::cout<< "Animal destructor called"<< std::endl;
}

Animal::Animal(const Animal &anml){
	std::cout<< "Animal copy constructor called"<< std::endl;
	*this = anml;
}

Animal &Animal::operator=(const Animal &anml){
	std::cout<< "Animal copy assignement called"<< std::endl;
	this->type = anml.type;
	return *this;
}

void Animal::makeSound(void)const{
	std::cout<< this->type<< " sound"<<std::endl;
}

std::string Animal::getType(void)const{
	return this->type;
}

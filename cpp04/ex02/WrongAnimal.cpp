#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	std::cout<< "WrongAnimal constructor called"<< std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(void){
	std::cout<< "WrongAnimal destructor called"<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &anml){
	std::cout<< "WrongAnimal copy constructor called"<< std::endl;
	*this = anml;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &anml){
	std::cout<< "WrongAnimal copy assignement called"<< std::endl;
	this->type = anml.type;
	return *this;
}

void WrongAnimal::makeSound(void)const{
	std::cout<< this->type<< " sound"<<std::endl;
}

std::string WrongAnimal::getType(void)const{
	return this->type;
}

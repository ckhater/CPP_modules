#include"Cat.hpp"

Cat::Cat(void){
	std::cout<< "Cat constructor called"<< std::endl;
	this->type = "Cat";
}

Cat::~Cat(void){
	std::cout<< "Cat destructor called"<< std::endl;
}

Cat::Cat(const Cat &ct):Animal(ct){
	std::cout<< "Cat copy constructor called"<< std::endl;
	*this = ct;
}

Cat &Cat::operator=(const Cat &ct){
	std::cout<< "Cat copy assignement called"<< std::endl;
	this->type = ct.type;
	return *this;
}

void Cat::makeSound(void)const{
	std::cout<< this->type<< " 🐱 meoooow"<< std::endl;
}


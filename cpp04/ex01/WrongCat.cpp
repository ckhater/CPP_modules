#include"WrongCat.hpp"

WrongCat::WrongCat(void){
	std::cout<< "WrongCat constructor called"<< std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat(void){
	std::cout<< "WrongCat destructor called"<< std::endl;
}

WrongCat::WrongCat(const WrongCat &ct):WrongAnimal(ct){
	std::cout<< "WrongCat copy constructor called"<< std::endl;
	*this = ct;
}

WrongCat &WrongCat::operator=(const WrongCat &ct){
	std::cout<< "WrongCat copy assignement called"<< std::endl;
	this->type = ct.type;
	return *this;
}

void WrongCat::makeSound(void)const{
	std::cout<< this->type<< " 🐱 meoooow"<< std::endl;
}


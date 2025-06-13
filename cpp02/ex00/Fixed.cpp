#include "Fixed.hpp"

const int Fixed::fract = 8;

Fixed::Fixed(void):value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fix){
    std::cout << "Copy constructor called" << std::endl;
    *this = fix;
}

Fixed& Fixed::operator=(Fixed const &fix){
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = fix.getRawBits();
    return *this;
}

int Fixed::getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->value);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

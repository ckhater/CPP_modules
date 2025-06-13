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
    this->value = fix.value;
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

Fixed::Fixed(const int i){
    std::cout << "Int constructor called" << std::endl;
    this->value = i * (1 << this->fract);
}

Fixed::Fixed(const float i){
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(roundf(i * (1 << this->fract)));
}

float   Fixed::toFloat(void)const{

    return(static_cast<float>(this->value) / (1 << this->fract));
}

int Fixed::toInt(void)const{
    return( static_cast<int>(roundf(this->value /(1 << this->fract))));
}

std::ostream &operator<<(std::ostream& out,const Fixed &f){
    out << f.toFloat();
    return(out);
}
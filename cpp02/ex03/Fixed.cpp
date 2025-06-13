#include "Fixed.hpp"

const int Fixed::fract = 8;
bool Fixed::p = 0;

Fixed::Fixed(void):value(0){}

Fixed::~Fixed(void){}

Fixed::Fixed(Fixed const &fix){
    *this = fix;
}

Fixed& Fixed::operator=(Fixed const &fix){
    this->value = fix.value;
    return *this;
}

int Fixed::getRawBits(void)const{
    return(this->value);
}

void Fixed::setRawBits(int const raw){
    this->value = raw;
}

Fixed::Fixed(const int i){
    this->value = i * (1 << this->fract);
}

Fixed::Fixed(const float i){
    this->value = static_cast<int>(roundf(i*(1<<this->fract)));
}

float   Fixed::toFloat(void)const{

    return(static_cast<float>(this->value) / (1<<this->fract));
}

int Fixed::toInt(void)const{
    return( static_cast<int>(roundf(this->value /(1<<this->fract))));
}

Fixed   &Fixed::operator++(void){
    this->value++;
    return *this;
}

Fixed   Fixed::operator++(int){
    Fixed old;

    old = *this;
    this->value++;
    return old;
}

Fixed   &Fixed::operator--(void){
    this->value--;
    return *this;
}

Fixed   Fixed::operator--(int){
    Fixed old;

    old = *this;
    this->value--;
    return old;
}

Fixed   Fixed::operator>(const Fixed &f2)const{
    if(this->toFloat() > f2.toFloat())
        return Fixed(1);
    return Fixed(0);
}

Fixed   Fixed::operator<(const Fixed &f2)const{
    if(this->toFloat() < f2.toFloat())
        return Fixed(1);
    return Fixed(0);
}

Fixed   Fixed::operator>=(const Fixed &f2)const{
    if(this->toFloat() >= f2.toFloat())
        return Fixed(1);
    return Fixed(0);
}

Fixed   Fixed::operator<=(const Fixed &f2)const{
    if(this->toFloat() <= f2.toFloat())
        return Fixed(1);
    return Fixed(0);
}

Fixed   Fixed::operator==(const Fixed &f2)const{
    if(this->toFloat() == f2.toFloat())
        return Fixed(1);
    return Fixed(0);
}

Fixed   Fixed::operator!=(const Fixed &f2)const{
    if(this->toFloat() != f2.toFloat())
        return Fixed(1);
    return Fixed(0);
}

std::ostream &operator<<(std::ostream& out,const Fixed &f){
    if(f.p == 1)
    {
        f.p = 0;
        return(out);
    }
    out << f.toFloat();
    return(out);
}

Fixed   Fixed::operator*(const Fixed &f2)const{
    return(Fixed(this->toFloat() * f2.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &f2)const{
    return(Fixed(this->toFloat() - f2.toFloat()));
}

Fixed   Fixed::operator+(const Fixed &f2)const{
    return(Fixed(this->toFloat() + f2.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &f2)const{
    if(f2.toInt() == 0)
    {
        std::cerr << "\033[31mError division by 0\033[0m" <<std::endl;
        this->p = 1;
        return (Fixed(0));
    }
    return(Fixed(this->toFloat() / f2.toFloat()));
}

Fixed Fixed::min(Fixed &f1, Fixed &f2){
    if(f1.toFloat() > f2.toFloat())
        return(f2);
    return(f1);
}

Fixed Fixed::max(Fixed &f1, Fixed &f2){
    if(f1.toFloat() > f2.toFloat())
        return(f1);
    return(f2);
}

Fixed const Fixed::min(Fixed const &f1, Fixed const &f2){
    if(f1.toFloat() > f2.toFloat())
        return(f2);
    return(f1);
}

Fixed const Fixed::max(Fixed const &f1, Fixed const &f2){
    if(f1.toFloat() > f2.toFloat())
        return(f1);
    return(f2);
}

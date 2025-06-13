#ifndef FIXED_HPP
#define FIXED_HPP

#include<iostream>
#include<cmath>

class Fixed
{
private:
	int value;
	static const int fract;

public:
	Fixed(void);
	Fixed(Fixed const &fix);
	Fixed &operator=(Fixed const &fix);
	~Fixed(void);
	Fixed(const float i);
	Fixed(const int i);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);

	int toInt( void ) const;
	static bool	p;
	float toFloat( void ) const;

	Fixed   operator+(const Fixed &f2)const;
	Fixed   operator*(const Fixed &f2)const;
	Fixed   operator-(const Fixed &f2)const;
	Fixed   operator/(const Fixed &f2)const;
	Fixed   operator>(const Fixed &f2)const;
	Fixed   operator<(const Fixed &f2)const;
	Fixed   operator>=(const Fixed &f2)const;
	Fixed   operator<=(const Fixed &f2)const;
	Fixed   operator==(const Fixed &f2)const;
	Fixed   operator!=(const Fixed &f2)const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static Fixed min(Fixed &f1, Fixed &f2);
	static Fixed max(Fixed &f1, Fixed &f2);
	static Fixed const min(Fixed const &f1, Fixed const &f2);
	static Fixed const max(Fixed const &f1, Fixed const &f2);

};
std::ostream& operator<<(std::ostream& out,const Fixed& f);
#endif
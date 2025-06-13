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
	Fixed(const int i);
	Fixed(const float i);
	Fixed(Fixed const &fix);
	~Fixed(void);
	Fixed &operator=(Fixed const &fix);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& out,const Fixed& f);

#endif
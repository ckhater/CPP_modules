#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int value;
	static const int fract;

public:
	Fixed(void);
	Fixed(Fixed const &fix);
	~Fixed(void);
	Fixed &operator=(Fixed const &fix);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif

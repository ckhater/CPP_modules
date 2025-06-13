
#ifndef WrongCAT_HPP
#define WrongCAT_HPP

#include"WrongAnimal.hpp"

class WrongCat:public WrongAnimal{
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(const WrongCat &ct);
		WrongCat &operator=(const WrongCat &ct);
		void makeSound()const;
};

#endif

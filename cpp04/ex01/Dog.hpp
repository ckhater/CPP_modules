#ifndef DOG_HPP
#define DOG_HPP

#include"Animal.hpp"

class Dog: public Animal{
	private:
		Brain *br;
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &dg);
		Dog &operator=(const Dog &dg);
		void	makeSound(void)const;
		std::string	getBrain(int i);
		void	setBrain(int i, std::string idea);
		
};

#endif

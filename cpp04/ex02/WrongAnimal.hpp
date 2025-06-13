#ifndef WrongANIMAL_HPP
#define WrongANIMAL_HPP

#include<iostream>

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &anml);
		WrongAnimal &operator=(const WrongAnimal &anml);
		void makeSound(void)const;
		std::string getType(void)const;
};


#endif

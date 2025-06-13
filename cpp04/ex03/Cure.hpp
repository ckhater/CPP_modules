#ifndef CURE_HPP
#define CURE_HPP

#include"AMateria.hpp"

class Cure: public AMateria{
	public:
		Cure();
		~Cure();
		Cure(Cure const &cr);
		Cure &operator=(Cure const &cr);
		AMateria *clone()const;
		void use(ICharacter& target);

};

#endif

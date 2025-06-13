#ifndef ICE_HPP
#define ICE_HPP

#include"AMateria.hpp"

class Ice: public AMateria{
	public:
		Ice();
		~Ice();
		Ice(Ice const &cr);
		Ice &operator=(Ice const &cr);
		AMateria *clone()const;
		void use(ICharacter& target);

};

#endif

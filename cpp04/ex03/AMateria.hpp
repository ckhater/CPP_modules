#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include<iostream>

#include"ICharacter.hpp"
class ICharacter;

class AMateria{
	protected:
		std::string type;
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(AMateria const &amat);
		AMateria &operator=(AMateria const &amat);
		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


#endif

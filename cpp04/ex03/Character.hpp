#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include"ICharacter.hpp"

typedef struct Node{
	AMateria *materia;
	struct Node *next;
}t_trash;

class Character : public ICharacter
{
	private:
		std::string	name;
		t_trash		*garb;
		int			count;
		AMateria	*inventory[4];
	public:
		Character();
		Character(std::string name);
		Character(Character const &chr);
		Character &operator=(Character const &chr);
		~Character();
		std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	};

void    New_Grab(t_trash **grab);
void    AddGarb(AMateria *m, t_trash *grab);
void    DeleGarb(t_trash **grab);

#endif

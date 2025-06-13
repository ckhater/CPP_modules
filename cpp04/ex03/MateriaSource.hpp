#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include"IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria *materia[4];
        int count;
	public:
        MateriaSource();
        MateriaSource(MateriaSource const &mts);
        MateriaSource &operator=(MateriaSource const &mts);
		~MateriaSource();
		void learnMateria(AMateria* mts);
		AMateria* createMateria(std::string const & type);
};

#endif
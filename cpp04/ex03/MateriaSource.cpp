#include"MateriaSource.hpp"

MateriaSource::MateriaSource(){
    std::cout<< "MateriaSource consructor called"<< std::endl;
    count = 0;
    for(int i = 0; i < 4; i++){
        materia[i] = NULL;
    }
}

MateriaSource::~MateriaSource(){
      for(int i = 0; i < 4; i++){
        if(materia[i])
        {
            delete materia[i];
        }
    }
    std::cout<< "MateriaSource destructor called"<< std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &mts){
    std::cout<< "MateriaSource copy constructor"<< std::endl;
    this->count = mts.count;
    for(int i = 0;i<4; i++){
        if(mts.materia[i])
            materia[i] = mts.materia[i]->clone();
        else
            materia[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &mts){
    this->count = mts.count;
    if(this != &mts)
    {
        for(int i = 0;i<4; i++){
        delete materia[i];
        if(mts.materia[i])
            materia[i] = mts.materia[i]->clone();
        else
            materia[i] = NULL;
    }
}
return *this;
}

void    MateriaSource::learnMateria(AMateria *mts){
    for(int i = 0;i<4; i++){
        if(!this->materia[i])
        {
            this->materia[i] = mts;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type){
    if(count > 3){
        return NULL;
    }
    for(int i=0; i < 4; i++){
        if(this->materia[i] && this->materia[i]->getType() == type)
        {
            count++;
            return this->materia[i]->clone();
        }
    }
    return NULL;
}

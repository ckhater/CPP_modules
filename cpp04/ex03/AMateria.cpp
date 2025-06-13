#include"AMateria.hpp"

AMateria::AMateria(){
    type = "AMateria";
}

AMateria::~AMateria(){
}

AMateria::AMateria(AMateria const &amat){
    *this = amat;
}

AMateria &AMateria::operator=(AMateria const &amat){
    this->type = amat.type;
    return *this;
}

AMateria::AMateria(std::string const &type){
    this->type = type;
}

std::string const &AMateria::getType()const{
    return this->type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses AMateria on " << target.getName() << " *" << std::endl;
}

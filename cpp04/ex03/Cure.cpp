#include"Cure.hpp"

Cure::Cure():AMateria("cure"){
    std::cout<< "Cure constructor called 💊"<< std::endl;
}

Cure::~Cure(){
    std::cout<< "Cure destructor called"<< std::endl;
}

Cure &Cure::operator=(Cure const &cr){
    this->type = cr.type;
    return *this;
}

Cure::Cure(Cure const &cr):AMateria(cr){
}

AMateria *Cure::clone()const{
    return new Cure();
}

void Cure::use(ICharacter& target){
    std::cout<< "*heals "<< target.getName()
             << "'s wounds *"<< std::endl;
}

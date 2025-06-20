#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string trg):AForm(trg,25, 5){
    std::cout<< "PresidentialPardonForm constructor called\n\n";
    this->target = trg;
    std::cout<<"\033[1m"<< target<< " has been pardoned by Zaphod Beeblebrox\033[0m\n";
}
 PresidentialPardonForm::~PresidentialPardonForm(void){
    std::cout<< "\nPresidentialPardonForm destructor called\n";
 }
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &prd):AForm(prd){
    std::cout<< "PresidentialPardonForm copy constructor called\n";
    *this = prd;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &prd){
    std::cout<< "PresidentialPardonForm copy assignement called\n";
    this->target = prd.target;
    return *this;
}

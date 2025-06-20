#include"Intern.hpp"

Intern::Intern(void){
    std::cout<<"Intern constructor called\n";
    aform[0] = "robotomy request";
    aform[1] = "presidential pardon";
    aform[2] = "shrubbery creation";
}

Intern::~Intern(void){
    std::cout<< "Intern destructor called\n";
}

Intern::Intern(Intern const &intr){
    std::cout<< "Intern copy constructor called\n";
    *this = intr;
}

Intern &Intern::operator=(Intern const &intr){
    std::cout<< "Intern copy assignement called\n";
    this->aform[0] = intr.aform[0];
    this->aform[1] = intr.aform[1];
    this->aform[2] = intr.aform[2];
    return *this;
}

AForm *Intern::makeForm(std::string form, std::string target){
    int i = 0;
    AForm *fct= NULL;
    while(i < 3)
    {
        if (form == aform[i])
        {
            std::cout<<"\033[32;1mIntern creates "<< form<<" successfully\033[0m\n"; 
            break;
        }
        i++;
    }
    switch (i)
    {
        case 0:
            fct = new RobotomyRequestForm(target);
            return fct;
        case 1:
            fct = new PresidentialPardonForm(target);
            return fct;
        case 2:
            fct = new ShrubberyCreationForm(target);
            return fct;
        default:
            std::cerr<<"\033[31;1mthis "<< form<<" doesn't exist\033[0m\n";
            return fct;
    }

}
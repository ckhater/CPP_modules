#ifndef INTERN_HPP
#define INTERN_HPP

#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"

class Intern{
    private:
        std::string aform[3];
    public:
        Intern(void);
        Intern(Intern const &intr);
        Intern &operator=(Intern const &intr);
        ~Intern(void);
        AForm *makeForm(std::string form, std::string target);
};

#endif
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include"AForm.hpp"

class PresidentialPardonForm: public AForm{
    private:
        std::string target;
        PresidentialPardonForm(void);
    public:
        PresidentialPardonForm(std::string trg);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm(PresidentialPardonForm const &prd);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &prd);
};

#endif
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include"AForm.hpp"
#include<cstdlib>
#include<ctime>

class RobotomyRequestForm: public AForm{
    private:
        std::string target;
        RobotomyRequestForm(void);
    public:
        RobotomyRequestForm(std::string trg);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm(RobotomyRequestForm const &rbt);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rbt);
};

#endif
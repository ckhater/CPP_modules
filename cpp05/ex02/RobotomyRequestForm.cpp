#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string trg):AForm(trg, 72, 45){
    std::cout<< "RobotomyRequestForm constructor called\n\n";
    this->target = trg;
    srand(time(0));
    std::cout<< "\033[1m🔧Drilling noise..\033[0m\n";
    if(rand()%2)
        std::cout<< target<< " has been robotomized successfully\n";
    else
        std::cout<< target<< " failed to be robotmized\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rbt):AForm(rbt){
    std::cout<< "RobotomyRequestForm copy constructor called\n";
    *this = rbt;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rbt){
    std::cout<< "RobotomyRequestForm copy assignement called\n";
    this->target = rbt.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    std::cout<< "\nRobotomyRequestForm destructor called\n";
}

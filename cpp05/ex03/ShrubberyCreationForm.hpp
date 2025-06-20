#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include"AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{
    private:
        std::string target;
        ShrubberyCreationForm(void);
    public:
		 ShrubberyCreationForm(std::string target);
		 ~ ShrubberyCreationForm(void);
		 ShrubberyCreationForm(ShrubberyCreationForm const &shrb);
		 ShrubberyCreationForm &operator=(ShrubberyCreationForm const &shrb); 
};
void    write_tree(std::fstream &file);
#endif

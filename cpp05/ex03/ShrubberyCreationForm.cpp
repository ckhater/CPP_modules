#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm(target, 145, 137){
    std::cout<< "ShrubberyCreationForm constructor called\n\n";
    std::fstream file;
    std::string str;

    this->target = target;
    str = target + "_shrubbery";
    file.open(str.c_str(),std::ios::out | std::ios::trunc);
    if(file.is_open())
        write_tree(file);
    else
        std::cerr<< "Error: No tree has been planted🥲\n";
}

void    write_tree(std::fstream &file){
file<< "            .     .  .      +     .      .          ."<<std::endl;
file<< "     .       .      .     #       .           ."<<std::endl;
file<< "        .      .         ###            .      .      ."<<std::endl;
file<< "      .      .   \"#:. .:##\"##:. .:#\"  .      ."<<std::endl;
file<< "          .      . \"####\"###\"####\"  ."<<std::endl;
file<< "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ."<<std::endl;
file<< "  .             \"#########\"#########\"        .        ."<<std::endl;
file<< "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ."<<std::endl;
file<< "     .     .  \"#######\"\"##\"##\"\"#######\"                  ."<<std::endl;
file<< "                .\"##\"#####\"#####\"##\"           .      ."<<std::endl;
file<< "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ."<<std::endl;
file<< "      .     \"#######\"##\"#####\"##\"#######\"      .     ."<<std::endl;
file<< "    .    .     \"#####\"\"#######\"\"#####\"    .      ."<<std::endl;
file<< "            .     \"      000      \"    .     ."<<std::endl;
file<< "       .         .   .   000     .        .       ."<<std::endl;
file<< ".. .. ..................O000O........................ ...... ..."<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    std::cout<< "\nShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrb):AForm(shrb){
    std::cout<< "ShrubberyCreationForm copy constructor called\n";
    *this = shrb;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrb){
    std::cout<< "ShrubberyCreationForm copy assignement called\n";
    this->target = shrb.target;
    return *this;
}

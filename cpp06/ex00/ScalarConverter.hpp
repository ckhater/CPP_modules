#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<climits>
#include<sstream>
class ScalarConverter{
    private:
        ScalarConverter(void);
        ~ScalarConverter(void);
        ScalarConverter(ScalarConverter const &sca);
        ScalarConverter& operator=(ScalarConverter const &sca);
    public:
        static void convert(std::string literal);
};
void    convertChar(std::string literal);
void    convertInt(std::string literal);
void    convertFloat(std::string literal);
void    convertDouble(std::string literal);
std::string const   check_pseu(std::string res);
bool                check_rest(std::string res);

#endif
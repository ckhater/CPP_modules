#include"ScalarConverter.hpp"

ScalarConverter::~ScalarConverter(){}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &sca){
    (void)sca;
    return *this;
}

std::string  const check_pseu(std::string res){
    if(res == "nan" || res == "nanf" || res == "NAN" || res == "NANF")
        return "nan";
    if(res == "INF" || res == "inf" || res == "INFF" || res == "inff")
        return "+inf";
    if(res == "+INF" || res == "+inf" || res == "+INFF" || res == "+inff")
        return "+inf";
    if(res == "-INF" || res == "-inf" || res == "-INFF" || res == "-inff")
        return "-inf";
    return "";
}

bool    check_rest(std::string res){
    long unsigned int i;

    i = 1;
    if(res.empty())
        return true;
    if(res[0] == '.' && res[1] != 'f')
    {
        while(i < res.length() - 1)
        {
            if(!isdigit(res[i]))
                return false;
            i++;
        }
        if(!isdigit(res[i]) && res[i] != 'f')
            return false;
        return true;
    }
    return false;
}

void    convertChar(std::string literal){
    long double i;
    char *ptr;
    std::string res;
    std::string ub;


    i = std::strtold(literal.c_str(), &ptr);
    std::strtol(literal.c_str(), &ptr, 10);
    res = ptr;
    ub = check_pseu(res);
    if( (i == 0 && res.length() > 1 && ub.empty() ) || (i && !check_rest(res) && ub.empty() ))  
    {
        std::cerr<< "\033[031mTakes only char or int or float or double\033[0m"<<std::endl;
        exit (EXIT_FAILURE);
    }
    else if (!ub.empty())
        std::cout<< "char: impossible"<< std::endl;
    else if (i == 0 && isprint(*ptr))
        std::cout<<"char: '"<< res<< "'"<<std::endl;
    else if (i > 0 && i < 255 && isprint(static_cast<char> (i)))
        std::cout<< "char: '"<< static_cast<char> (i)<< "'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
}

void    convertInt(std::string literal){
    long double i;
    char *ptr;
    std::string res;
    std::string ub;

    i = std::strtold(literal.c_str(), &ptr);
    std::strtol(literal.c_str(), &ptr, 10);
    res = ptr;
    ub = check_pseu(res);
    if(!ub.empty() || (i > INT_MAX || i < INT_MIN))
        std::cout<<"int: impossible"<< std::endl;
    else if (i == 0)
        std::cout<< "int: "<< static_cast<int>(*ptr)<<std::endl;
    else
        std::cout<< "int: "<< static_cast<int>(i)<<std::endl;
}

void    convertFloat(std::string literal){
    float i;
    char *ptr;
    std::string res;
    unsigned int j;

    i = strtof(literal.c_str(),&ptr);
    std::strtol(literal.c_str(), &ptr,10);
    res = ptr;
    if(i != 0 && res.empty())
        std::cout<< std::fixed << std::setprecision(1)<<"float: "<< i<<"f"<<std::endl;
    else if(i == 0)
        std::cout<< std::fixed << std::setprecision(1)<<"float: "<< static_cast<float>(*ptr)<<"f"<<std::endl;
    else
    {
        j = res.length() - 1;
        if(res[j] == 'f')
            j -= 1;
        std::cout<<std::fixed << std::setprecision(j)<<"float: "<< i<<"f"<<std::endl;
    }
    // std::cout << std::resetiosflags(std::ios_base::floatfield);
}

void    convertDouble(std::string literal){
    double i;
    char *ptr;
    std::string res;

    i = strtod(literal.c_str(),&ptr);
    if(i == 0)
        std::cout<<"double: "<< static_cast<double>(*ptr)<<std::endl;
    else
        std::cout<< "double: "<< i<<std::endl;
}

void    ScalarConverter::convert(std::string literal){    
    convertChar(literal);
    convertInt(literal);
    convertFloat(literal);
    convertDouble(literal);
}
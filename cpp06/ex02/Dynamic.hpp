#ifndef DYNAMIC_HPP
#define DYNAMIC_HPP

#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

#include<cstdlib>
#include<ctime>
#include<exception>


Base * generate(void);

void identify(Base* p);
void identify(Base& p);

#endif
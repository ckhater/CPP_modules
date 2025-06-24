#include"Dynamic.hpp"

Base* generate(void){
    unsigned int n;
    srand(time(0));
    n = rand();
    if(n % 3 == 1){
        return new A;
    }
    else if(n % 3 == 2){
        return new B;
    }
    else
        return new C;
}

void    identify(Base* p)
{
    if(dynamic_cast<A*>(p))
       std::cout<<"Base == A\n";
    else if(dynamic_cast<C*>(p))
        std::cout<<"Base == C\n"; 
    else if(dynamic_cast<B*>(p))
        std::cout<<"Base == B\n";
    else 
        std::cout<<"Error\n";
    
}

void    identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout<<"Base == A\n";
    }
    catch(std::exception &e)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout<<"Base == B\n";
        }
        catch(std::exception &e)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout<<"Base == C\n";
            }
            catch(std::exception &e)
            {
                std::cout<<e.what()<<std::endl;
            }
        }
    }
}
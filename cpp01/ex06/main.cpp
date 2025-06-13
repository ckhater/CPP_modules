#include"Harl.hpp"

int main(int ac, char **av)
{
    Harl har;

    switch (ac)
    {
        case 2:
            har.complain(av[1]);
            break;
        default:
            std::cerr<<"\033[31mError\033[0m"<<std::endl;
            return(1);
    }
    
    return(0);
}
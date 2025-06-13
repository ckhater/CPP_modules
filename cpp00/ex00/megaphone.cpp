#include <iostream>
#include <cctype>
#include <cstring>

void    capit(char *str)
{
    size_t i;

    i = 0;
    while(i < strlen(str))
    {
        str[i] = toupper((unsigned char)str[i]);
        std::cout<<str[i];
        i++;
    }
}

int main(int ac, char **av) 
{
    int i;

    i = 1;

    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while( i < ac)
        {
            capit(av[i]);
            i++;
        }
    }
}
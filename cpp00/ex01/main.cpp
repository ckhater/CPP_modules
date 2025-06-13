#include "PhoneBook.hpp"

void printError(std::string str, int i)
{
    if(i == 0)
    {
        std::cout<<"Please enter the "<<str<<" of the contact"<<std::endl;
        std::cout<<"\033[1;36m>\033[0m";
    }
    else if(i == 1)
        std::cout<<"\033[31mthe input should be a bunch of characters\033[0m"<<std::endl;
    else if(i == 2)
        std::cout<<"\033[31mthe input should be a number\033[0m"<<std::endl;
}

bool checkSpace(const std::string str)
{
    int i = 0;
    long unsigned int cnt = 0;
    while(str[i])
    {
        if(!isalpha(str[i]) && !isspace(str[i]))
            return(1);
        if(isspace(str[i])) 
            cnt++;
        i++;
    }
    if(cnt == str.length())
        return(1);
    return(0);
}

bool checkNumber(const std::string str)
{
    double num;
    std::istringstream st(str);
    st >> num;
    if(st.fail() || !st.eof() || num < 0 || str.length() > 15)
        return(1);
    return(0);
}


int main()
{
    PhoneBook phonebook;
    std::string str;
    int i=0;

    phonebook.j = 0;
    while(1)
    {
        std::cout<<"\033[21;36mPlease enter one of the commands EXIT ,ADD or SEARCH\033[0m"<<std::endl;
        std::cout<<"\033[1;36m>\033[0m";
        if (!std::getline(std::cin, str))
            break;
        else if(str == "EXIT")
            break;
        else if (str == "ADD")
        {
            phonebook.setIndex(i%8);
            if(!phonebook.addContact())
                break;
            i++;
            phonebook.j = i;
        }
        else if (str == "SEARCH")
        {
            if(!phonebook.searchContact())
                break;
        }
        else
            std::cout << "🚨 \033[31mOnly three commands available EXIT ,ADD and SEARCH\033[0m" << std::endl;
    }
    return(0);
}

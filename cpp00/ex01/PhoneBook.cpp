#include "PhoneBook.hpp"

void PhoneBook::setIndex(int i)
{
    index = i;
}

int PhoneBook::getIndex(void)
{
    return(index);
}

bool getContact(std::string &str, std::string str1, Contact &contact)
{
    printError(str1, 0);
    if(!std::getline(std::cin, str))
        return(0);
    if(str.empty())
    {
        if(!getContact(str, str1, contact))
            return(0);
    }
    else if(str1 == "phone" && checkNumber(str))
    {
        printError(str1, 2);
        if(!getContact(str, str1, contact))
            return(0);
    }
    else if(str1 != "phone" && checkSpace(str))
    {
        printError(str1, 1);
        if(!getContact(str, str1, contact))
            return(0);
    }
    return(1);
}

std::string teenChara(std::string str)
{
    int i = 0;
    int j = 0;
    if(str.length() > 10)
        return(str.substr(0, 9)+".");
    i = 10 -str.length();
    while(i > j)
    {
        str = " "+str;
        j++;
    }
    return(str);
}

void PhoneBook::printContact(void)
{
    int i = 0;
    std::cout<<"|     Index|First Name| Last Name|  Nickname|"<<std::endl;
    if(j > 8)
        j = 8;
    while(i < j )
    {
        std::cout<<"|         "<<i<<"|";
        std::cout<<teenChara(contacts[i].getName())<<"|";
        std::cout<<teenChara(contacts[i].getLastname())<<"|";
        std::cout<<teenChara(contacts[i].getNickname())<<"|";
        std::cout<<std::endl;
        i++;
    }
}



bool PhoneBook::searchContact()
{
    std::string str;
    int num;

    printContact();
    std::cout<<"\033[21mEnter the index of the contact you want to display\033[0m"<<std::endl;
    if(!std::getline(std::cin, str))
        return(0);
    std::istringstream ss(str);
    ss >> num;
    if(ss.fail() || !ss.eof())
        std::cout<<"\033[31mInvalid input !!!\033[0m"<<std::endl;
    else if (num >= 8 || num < 0)
        std::cout<<"\033[31mInvalid index !!!The index should be between 0-7\033[0m"<<std::endl;
    else
    {
        if (j == 0)
            std::cout<<"\033[31mFill the contact\033[0m"<<std::endl;
        else if(num > j -1 )
            std::cout<<"\033[31mContact not found\033[0m"<<std::endl;
        else
        {
            std::cout<<"Name: "<<contacts[num].getName()<<std::endl
                     <<"Last_Name: "<<contacts[num].getLastname()<<std::endl
                     <<"Nick_Name: "<<contacts[num].getNickname()<<std::endl
                     <<"Phone_Number: "<<contacts[num].getPhonenmbr()<<std::endl
                     <<"Darkest_secret: "<<contacts[num].getDarkestsecret()<<std::endl;
        }
    }

   return(1);
}


bool PhoneBook::addContact()
{
    std::string tname;
    std::string tphone;
    std::string tsecret;
    std::string tnickname;
    std::string tlastname;
    Contact& c = contacts[getIndex()];

    std::cout<<"\033[21m                                    \033[0m"<<std::endl;
    if(!getContact(tname, "name", c))
        return(0);
    c.setName(tname);
    if(!getContact(tlastname, "lastname", c))
        return(0);
    c.setLastname(tlastname);
    if(!getContact(tnickname, "nickname", c))
        return(0);
    c.setNickname(tnickname);
    if(!getContact(tphone, "phone", c))
        return(0);
    c.setPhonenmbr(tphone);
    if(!getContact(tsecret, "secret", c))
        return(0);
    c.setDarkestsecret(tsecret);
    return(1);
}
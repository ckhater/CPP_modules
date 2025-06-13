#include "Contact.hpp"

void Contact::setPhonenmbr(std::string tphonenmbr)
{
    phonenmbr = tphonenmbr;
}

void Contact::setName(std::string tname)
{
    name = tname;
}

void Contact::setLastname(std::string tlastname)
{
    lastname = tlastname;
}

void Contact::setNickname(std::string tnickname)
{
    nickname = tnickname;
}

void Contact::setDarkestsecret(std::string tdarkestsecret)
{
    darkestsecret = tdarkestsecret;
}

std::string Contact::getName(void)
{
    return(name);
}

std::string Contact::getPhonenmbr(void)
{
    return(phonenmbr);
}

std::string Contact::getLastname(void)
{
    return(lastname);
}

std::string Contact::getDarkestsecret(void)
{
    return(darkestsecret);
}

std::string Contact::getNickname(void)
{
    return(nickname);
}





#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

bool checkSpace(const std::string str);
bool checkNumber(const std::string str);
void printError(std::string str, int i);



class PhoneBook{
    private:
        int index;
    public:
        Contact contacts[8];
        bool addContact();
        bool searchContact();
        void setIndex(int i);
        void printContact();
        int getIndex(void);
        int j;
};


#endif

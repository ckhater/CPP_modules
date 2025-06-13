#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>

class Contact{

    private:
        std::string name;
        std::string lastname;
        std::string nickname;
        std::string phonenmbr;
        std::string darkestsecret;
    public:
        void setDarkestsecret(std::string tdarkestsecret);
        void setPhonenmbr(std::string tphonenmbr);
        void setLastname(std::string tlastname);
        void setNickname(std::string tnickname);
        void setName(std::string tname);
        std::string getName(void);
        std::string getLastname(void);
        std::string getNickname(void);
        std::string getPhonenmbr(void);
        std::string getDarkestsecret(void);
};


#endif

#include"Harl.hpp"

void    Harl::debug(){
    std::cout<<"[ Debug ]"<<std::endl
             <<"I love having extra bacon for my 7XL-double-cheese-triple-pickle"
             <<"-specialketchup burger. I really do!"
             <<std::endl;
}

void    Harl::info(){
    std::cout<<"[ Info]"<<std::endl
             <<"I cannot believe adding extra bacon costs more money. You didn’t put"
             <<" enough bacon in my burger! If you did, I wouldn’t be asking for more!"
             <<std::endl;
}

void    Harl::warning(){
    std::cout<<"[ Warning ]"<<std::endl
             <<"I think I deserve to have some extra bacon for free. I’ve been coming for"
             <<" years whereas you started working here since last month."
             <<std::endl;
}

void    Harl::error(){
    std::cout<<"[ Error ]"<<std::endl
             <<"This is unacceptable! I want to speak to the manager now."
             <<std::endl;
}

void    Harl::complain(std::string level){
    Harl har;
    int i = 0;
    std::string str[4] = {"debug", "info", "warning", "error"};
    void (Harl:: *lev[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    while(i < 4)
    {
        if(level == str[i])
            break;
        i++;
    }

    switch (i)
    {
        case 0:
            (har.*lev[i])();
            i++;
        case 1:
            (har.*lev[i])();
            i++;
        case 2:
            (har.*lev[i])();
            i++;
        case 3:
            (har.*lev[i])();
            break;
        default:
            std::cerr<<"\033[31mError\033[0m"<<std::endl;
            std::cerr<<"debug, info, warning, error"<<std::endl;
            break;
    }
}
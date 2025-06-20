#include<iostream>
#include<string>
#include<fstream>

void    fct_replace(std::string s1,std::string s2,std::fstream &file, std::fstream &nfile)
{
    std::string str;
    size_t pos;
    while(std::getline(file,str))
    {
        while(str.find(s1) !=std::string::npos)
        {
            pos = str.find(s1);
            str.erase(pos,s1.length());
            str = str.substr(0, pos) + s2 + str.substr(pos);
        }
        nfile<<str<<std::endl;
    }
    file.close();
    nfile.close();
    return;
}

int main(int ac, char **av)
{
    std::fstream file;
    std::fstream nfile;
    std::string  str;

    if(ac == 4)
    {
        str =std::string(av[1]) + ".replace";
        file.open(av[1], std::ios::in);
        if(file.is_open())
        {
            nfile.open(str.c_str(),std::ios::out | std::ios::trunc);
            if(nfile.is_open())
                fct_replace(av[2],av[3],file,nfile);
            else{
                std::cerr<<"\033[31mError\033[0m"<<std::endl;
                file.close();
                return(1);
            }
        }
        else
        {
            std::cerr<<"\033[31mError\033[0m"<<std::endl;
            return(1);
        }
    }
    else
    {
        std::cerr<<"\033[31mError\033[0m"<<std::endl
                 <<"./replace <filename> string1 string2"<<std::endl;
        return(1);
    }

    return(0);
}

#include"BitcoinExchange.hpp"

MyError::MyError(std::string m):msg(m){}

MyError::MyError(const MyError &err):std::exception(err){
    this->msg = err.msg;
}

MyError::MyError(const MyError &err){}
MyError &MyError::operator=(const MyError &err){
    std::exception::operator=(err);
    this->msg = err.msg;
    return *this;
}

MyError::~MyError() throw(){
    std::exception::~exception();
}

const char * MyError::what() const throw(){
    return this->msg.c_str();
}

int     valiDate(std::vector<int> vect){
    int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((vect[0] % 4 == 0) && ((vect[0] % 100 != 0) || (vect[0] % 400 == 0))){
        mon[1] = 29;
    }
    if(vect[1] > 0 && vect[1] < 13){
        if(vect[2] <= mon[vect[1] - 1] && vect[2] > 0)
            return 1;
    }
    std::cout<<"Error: bad input => "<<vect[0]<<'-'
             <<vect[1]<<'-'<<vect[2]<<std::endl;
    return 0;
    
}

int     checkDate(std::vector<int> &vect,std::map<std::vector<int>,float> &mp, std::string str, float *pr){
    std::string ed;
    char *ptr;

    std::stringstream ss(str);
    std::getline(ss,ed,'-');
    if(ed.length() == 4 && ed[0] == '2'){
        vect[0] = std::strtol(ed.c_str(),&ptr,10);
        std::getline(ss,ed,'-');
        vect[1] = std::strtol(ed.c_str(),&ptr,10);
        std::getline(ss,ed,'-');
        vect[2] = std::strtol(ed.c_str(),&ptr,10);
        if(valiDate(vect)){
            std::map<std::vector<int>, float>::iterator it = mp.lower_bound(vect);
            std::map<std::vector<int>, float>::iterator ls = mp.end();
            --ls;
            if (it != mp.end() && vect >= it->first)
                *pr =  it->second;
            else {
                if(it == mp.begin() || vect > ls->first){
                    std::cout<<"Error: unfound input => "<<str<<std::endl;
                    return 0;
                }
                else { 
                    --it;
                    *pr =  it->second;
                }
            }
            return 1;
        }
    }
    else
        std::cout<<"Error: bad input => "<<str<<std::endl;
    return 0;
}

void    getValue(std::string ed, std::vector<int> vect, float pr){
    char *ptr;
    float value;

    if(ed.empty()){
        std::cout<<"Error: no value"<<std::endl;
        return;
    }
    value = std::strtof(ed.c_str(), &ptr);
    if(ptr == ed)
    {
        std::cout<<"Error: bad value => "<<ed<<std::endl;
        return;
    }
    if(value < 0){
        std::cout<< "Error: not a positive number."<<std::endl;
        return;
    }
    if(value > 1000){
        std::cout<< "Error: too large a number."<<std::endl;
        return ;
    }
    std::cout<<vect[0]<<'-'<< std::setfill('0') << std::setw(2)<<vect[1]
             <<'-'<< std::setfill('0') << std::setw(2)<<vect[2]
             <<" => "<<value<<" = "<<value * pr<<std::endl;
}

void    BitcoinExchange::getprice(std::fstream &file){
    std::vector<int> vect(3);
    std::string str;
    std::string ed;
    float   pr;

    std::getline(file,str);
    if(str != "date | value"){
        file.close();
        throw MyError("\033[31mError: bad input => date | value\033[0m]");
    }
    else{
        while(std::getline(file,str)){
            std::stringstream ss(str);
            std::getline(ss,ed, '|');
            if(checkDate(vect, this->mp, ed, &pr)){
                if(std::getline(ss,ed, '|'))
                    getValue(ed,vect,pr);
                else
                    std::cout<<"Error: no value"<<std::endl;
            }
        }
    }
}

void    getData(std::fstream &file, std::map<std::vector<int>,float> &mp){
    std::string str;
    std::string part;
    std::vector<int> vect(3);
    int i;
    char *ptr;

    std::getline(file,str);
    while(std::getline(file,str)){
        std::stringstream ss(str);
        i = 0;
        while (std::getline(ss, part, '-')) {
            vect[i] =  std::strtol(part.c_str(), &ptr,10);
            i++;
        }
        mp.insert(std::make_pair(vect,std::strtof(ptr+1,&ptr)));
    }
}

BitcoinExchange::BitcoinExchange(void){
    std::fstream file;

    file.open("data.csv",std::fstream::in);
    if(file.is_open()){
        getData(file,this->mp);
        file.close();
    }
    else
        throw MyError("\033[31mError:\n  failed to open data.csv\033[0m");
}



BitcoinExchange::~BitcoinExchange(void){
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc){
    (void)btc;
    return *this;
}

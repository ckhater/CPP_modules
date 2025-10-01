#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<iostream>
#include<iomanip>
#include<exception>
#include<string>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<map>
#include<vector>


class MyError : public std::exception{
    private:
    std::string msg;
    public:
        MyError(const MyError &err);
        MyError &operator=(const MyError &err);
        MyError(std::string m);
        const char * what() const throw();
        ~MyError() throw();
};

class BitcoinExchange{
    private:
        std::map<std::vector<int>,float> mp;
        BitcoinExchange(const BitcoinExchange &btc);
        BitcoinExchange &operator=(const BitcoinExchange &btc);
    public:
        BitcoinExchange(void);
        void getprice(std::fstream &file);
        ~BitcoinExchange(void);
};

int     valiDate(std::vector<int> vect);
void    getValue(std::string ed, std::vector<int> vect, float pr);
void    getData(std::fstream &file, std::map<std::vector<int>,float> &mp);
int     checkDate(std::vector<int> &vect,std::map<std::vector<int>,float> &mp, std::string str, float *pr);

#endif
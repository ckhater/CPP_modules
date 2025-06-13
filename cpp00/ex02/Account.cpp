#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Account::Account(){return;}

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbAccounts++;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"
             <<_amount<<";created"<<std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"
             <<_amount<<";closed"<<std::endl;
}

int Account::getNbAccounts(void){
    return _nbAccounts;
}

int Account::getTotalAmount(void){
    return _totalAmount;
}

int Account::getNbDeposits(void){
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout<<"accounts:"<<getNbAccounts()<<";total:"
             <<getTotalAmount()<<";deposits:"<<getNbDeposits()
             <<";withdrawals:"<<getNbWithdrawals()<<std::endl;
    _totalAmount = 0;
}

void    Account::makeDeposit(int deposit){
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount;
    _amount += deposit;
    _totalAmount += _amount;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout<<";deposit:"<<deposit<<";amount:"<<checkAmount()
             <<";nb_deposits:"<<_nbDeposits<<std::endl;
}

bool    Account::makeWithdrawal(int withdrawl){
    int newAmount;
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount;
    newAmount = _amount - withdrawl;
    if(newAmount < 0)
    {
        std::cout<<";withdrawal:refused"<<std::endl;
        _totalAmount += _amount;
        return(1);
    }
    _amount = newAmount;
    _totalAmount += _amount;
    _nbWithdrawals++;
    _totalNbWithdrawals += _nbWithdrawals;
    std::cout<<";withdrawal:"<<withdrawl<<";amount:"
             <<checkAmount()<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
    return(0);
}

int Account::checkAmount(void)const{
    return(_amount);
}

void Account::displayStatus(void)const{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"
             <<_amount<<";deposits:"<<_nbDeposits
             <<";withdrawals:"<<_nbWithdrawals<<std::endl;
}


void Account::_displayTimestamp(void)
{
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    
    std::cout << "["
              << 1900 + ltm->tm_year
              << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
              << std::setfill('0') << std::setw(2) << ltm->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << ltm->tm_hour
              << std::setfill('0') << std::setw(2) << ltm->tm_min
              << std::setfill('0') << std::setw(2) << ltm->tm_sec
              << "] ";
}


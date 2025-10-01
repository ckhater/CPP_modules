#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<ctime>
#include<list>
#include<set>
#include<deque>

class PmergeMe{
    private:
        std::list<int> lst;
        std::deque<int> dq;
        std::deque<int> unsorted;
        clock_t start;
        clock_t end;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &pm);
        PmergeMe &operator=(const PmergeMe &pm);
        bool  getArgs(std::list<int> &cp);
        void    Pmergelist(void);
        void    Pmergedeque(void);
};

#endif
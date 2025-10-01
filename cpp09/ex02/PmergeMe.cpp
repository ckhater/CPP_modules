#include"PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &pm){
    *this = pm;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pm){
    this->lst = pm.lst;
    this->dq = pm.dq;
    return *this; 
}

bool    PmergeMe::getArgs(std::list<int> &cp){
    std::set<int> check;

    for(std::list<int>::iterator i = cp.begin(); i != cp.end(); ++i){
        check.insert(*i);
    }
    if(check.size() != cp.size())
        return true;
    for(std::list<int>::iterator i = cp.begin(); i != cp.end(); ++i){
        this->lst.push_back(*i);
        this->dq.push_back(*i);
        this->unsorted.push_back(*i);
    }
    return false;
}

std::list<size_t>    jackobsthal_lst(size_t size){
    std::list<size_t>  jc;
    size_t n,p,s;

    if(size >= 1){
        jc.push_back(0);
        s = 0;
    }
    if(size >= 2){
        jc.push_back(1);
        p = 1;
    }
    if(size < 3)
        return jc;
    n = (s*2) + p;
    for(size_t i = 0;i < size - 2 && n <= size + 2; i++){
        jc.push_back(n);
        s = p;
        p = n;
        n = (s*2) + p;
    }
    return jc;
}

void    binaryInsert(std::list<int> &l, int i){
    std::list<int>::iterator it ;
    std::list<int>::iterator low = l.begin(), high =l.end();
    int count, step;

    count = std::distance(low, high);
    while (count > 0) {
        it = low;
        step = count / 2;
        std::advance(it, step);
        if (*it < i) {
            low = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    l.insert(low, i);
}

void    fordJhonson_lst(std::list<int> &lst){
    int l;
    int s;
    std::list<int> larg;
    std::list<int> small;

    if(lst.size() <= 1)
        return;
    for(std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
        l = *it;
        ++it;
        if(it == lst.end()){
            larg.push_back(l);
            break;
        }
        s = *it;
        if(l > s){
            larg.push_back(l);
            small.push_back(s);
        }
        else{
            larg.push_back(s);
            small.push_back(l);
        }
    }
    fordJhonson_lst(larg);
    size_t si = small.size();
    std::list<size_t> jc = jackobsthal_lst(si);
    std::list<bool> insert(si,false);
    for(std::list<size_t>::iterator it = jc.begin(); it != jc.end();++it){
        std::list<bool>::iterator ins = insert.begin();
        size_t i = *it;
        std::advance(ins,i);
        if(i < si && !*ins){
            std::list<int>::iterator sm = small.begin();
            std::advance(sm,i);
            binaryInsert(larg,*sm);
            *ins = true;
        }
    }
    for(size_t j = 0; j < si;j++){
        std::list<bool>::iterator ins = insert.begin();
        std::advance(ins,j);
        if(!*ins){
            std::list<int>::iterator sm = small.begin();
            std::advance(sm,j);
            binaryInsert(larg,*sm);
            *ins = true;
        }
    }
    lst = larg;
}

void    PmergeMe::Pmergelist(void){

    this->start = clock();
    fordJhonson_lst(lst);
    this->end = clock();
}

std::deque<size_t> jackobsthal(size_t size){
    std::deque<size_t> jc;
    size_t n,p,s;

    if(size >= 1){
        jc.push_back(0);
        s = 0;
    }
    if(size >= 2){
        jc.push_back(1);
        p = 1;
    }
    if(size < 3)
        return jc;
    n = (s*2) + p;
    for(size_t i = 0;i < size - 2 && n <= size + 2; i++){
        jc.push_back(n);
        s = p;
        p = n;
        n = (s*2) + p;
    }
    return jc;
}

void    fordJhonson(std::deque<int> &dq){
    std::deque<int> large;
    std::deque<int> small;
    size_t  size;
    int f;
    int s;

    size_t dq_size = dq.size();
    if(dq_size <= 1)
        return;
    for(size_t i = 0; i < dq_size; i++){
        f = dq[i];
        i++;
        if(i == dq_size){
            large.push_back(f);
            break;
        }
        s = dq[i];
        if(f > s){
            large.push_back(f);
            small.push_back(s);
        }
        else{
            large.push_back(s);
            small.push_back(f);  
        }
    }
    fordJhonson(large);
    size = small.size();
    std::deque<size_t> jc = jackobsthal(size);
    std::deque<bool> insert(size,false);
    for(size_t i = 0; i < jc.size(); i++){
        size_t idx = jc[i];
        if(idx < size && !insert[idx]){
            std::deque<int>::iterator it = std::lower_bound(large.begin(),large.end(),small[idx]);
            large.insert(it,small[idx]);
            insert[idx] = true;
        }
    }
    for(size_t i = 0; i < size; i++){
        if(!insert[i]){
            std::deque<int>::iterator it = std::lower_bound(large.begin(),large.end(),small[i]);
            large.insert(it,small[i]);
            insert[i] = true;
        }
    }
    dq = large;
}

void    PmergeMe::Pmergedeque(void){
    size_t s = this->dq.size();
    clock_t sta = clock();
    fordJhonson(dq);
    clock_t ed = clock();
    std::cout<<"Befor: ";
    for(size_t i = 0; i < s; i++){
        std::cout<<' '<<unsorted[i];
    }
    std::cout<<std::endl;
       std::cout<<"After: ";
    for(size_t i = 0; i < s; i++){
        std::cout<<' '<<dq[i];
    }
    std::cout<<std::endl;
    std::cout<<std::fixed << std::setprecision(2)<<"Time to process a range of "<<lst.size()<<" elements with std::list  : "<< double(this->end - this->start) / CLOCKS_PER_SEC * 1e6 <<" us"<<std::endl;
    std::cout<<std::fixed << std::setprecision(2)<<"Time to process a range of "<<lst.size()<<" elements with std::deque : "<< double(ed - sta) / CLOCKS_PER_SEC *1e6 <<" us"<<std::endl;

}

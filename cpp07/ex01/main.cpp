#include"Iter.hpp"


int main( void )
{
    int l = 3;

    int const arr[] = {89, 78, 23};
    iter(arr, l,print);

    std::cout<<"\n**************************\n";
    const char* str[5] = {"test0", "test1", "test2", "test3"};
    iter(str, l,print);

    std::cout<<"\n**************************\n";
    float fl[]= {78.36, 45, 14.56, 852.36};
    iter(fl, l,print);

    std::cout<<"\n**************************\n";
    std::string st[]={"again0", "again1", "again2", "again10"};
    iter(st,l,print);
}


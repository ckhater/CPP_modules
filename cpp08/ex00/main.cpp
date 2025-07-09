#include"easyfind.hpp"
#define tar 15
int main(){
    int i;
    try{
        std::vector<int> vect;
        vect.push_back(3);
        vect.push_back(4);
        vect.push_back(6);
        vect.push_back(7);
        i = easyfind(vect,tar);
        std::cout<<"the taget is found:\n    arr["<<i<<"]= "<<tar<<std::endl;
    }
    catch(MyException &e){
         std::cerr << e.what() << '\n';
    }
    try{
        std::list<int>li;
        li.push_back(10);
        li.push_back(11);
        li.push_back(80);
        li.push_back(9);
        li.push_back(15);
         i = easyfind(li, tar);
        std::cout<<"the taget is found:\n    arr["<<i<<"]= "<<tar<<std::endl;
    }
    catch(MyException &e){
            std::cerr << e.what() << '\n';
    }
    return 0;
}

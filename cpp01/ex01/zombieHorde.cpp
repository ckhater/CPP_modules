#include"Zombie.hpp"

void Zombie::setName(std::string str){
    name = str;
 }

Zombie* zombieHorde( int N, std::string name ){
    Zombie* obj = new Zombie[N];

    int i = 0;
    while(i < N)
    {
        obj[i].setName(name);
        obj[i].announce();
        i++;
    }
    return(obj);
}
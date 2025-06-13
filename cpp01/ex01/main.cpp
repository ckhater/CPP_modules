#include"Zombie.hpp"

int main()
{
    Zombie* obj = zombieHorde(10,"foo");
    
    delete[] obj;
}
#include"Zombie.hpp"

int main()
{
    Zombie obj("foo");
    Zombie* nobj = newZombie("Weii");

    obj.announce();
    nobj->announce();
    randomChump("tee");
    delete nobj;
}
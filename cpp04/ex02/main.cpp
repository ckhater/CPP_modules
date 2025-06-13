#include"Dog.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"

int main (){
	// const Animal *i = new Dog();
	// const Animal *j = new Cat();

	Dog see;
	see.setBrain(0,"waaaa");
	Dog se = see;
	se.setBrain(0,"boooo");
	std::cout<< see.getBrain(0)<<std::endl<<se.getBrain(0)<<std::endl;
	// delete i;
	// delete j;
}

#include"Dog.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"
int main (){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();
	std::cout<< "***************************************"<< std::endl;
	const WrongAnimal* wr = new WrongAnimal();
	const WrongAnimal* wrc = new WrongCat();
	std::cout<< wr->getType()<< std::endl;
	std::cout<< wrc->getType()<< std::endl;
	wr->makeSound();
	wrc->makeSound();
	delete meta;
	delete j;
	delete i;
	delete wr;
	delete wrc;
}

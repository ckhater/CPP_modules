#include"Brain.hpp"

Brain::Brain(void){
	std::cout<< "🧠 Brain constructor called"<< std::endl;
}

Brain::~Brain(void){
	std::cout<< "🧠 Brain destructor called"<< std::endl;
}

Brain::Brain(Brain const &br){
	std::cout<< "🧠 Brain copy constructor called"<< std::endl;
	*this = br;
}

Brain &Brain::operator=(Brain const &br){
	std::cout<< "🧠Brain copy assignement called"<< std::endl;
	int i =0;
	while(i < 100)
	{
		this->ideas[i] = br.ideas[i];
		i++;
	}
	return *this;
}

std::string Brain::getIdea(int i)
{
	if(i > 100 || i < 0)
	{
		std::cout<< "⁉️ this idea doesn't exist";
		return "";
	}
	return this->ideas[i];
}

void Brain::setIdea(int i, std::string idea){
	if(i < 0 || i >= 100)
	{
		std::cout<< "from 0️⃣ to 9️⃣9️⃣"<< std::endl;
		return;
	}
	this->ideas[i] = idea;
}



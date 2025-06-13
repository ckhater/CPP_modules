#ifndef BRAIN_HPP
#define BRAIN_HPP

#include<iostream>

class Brain{
		  private:
			  std::string ideas[100];
		  public:
			  Brain(void);
			  ~Brain(void);
			  Brain(Brain const &br);
			  Brain &operator=(Brain const &br);
			  std::string getIdea(int i);
			  void setIdea(int i, std::string idea);

};

#endif

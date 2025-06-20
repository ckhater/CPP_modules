#include"Bureaucrat.hpp"

int main(){

	try{
		Bureaucrat obj("mimi",1);
		std::cout<<obj<<std::endl;
		obj.IncrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout<< "caught: "<< e.what()<< std::endl;
	}

	try{
		Bureaucrat obj("lili",150);
		std::cout<<obj<<std::endl;
		obj.DecrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout<<"caught: "<< e.what()<< std::endl;
	}

    return 0;
}

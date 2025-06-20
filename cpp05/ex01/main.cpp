#include"Form.hpp"

int main(){

	try{
		Form obj("mimi",1,45);
		std::cout<<obj<<std::endl;
	}
	catch(std::exception &e)
	{
		std::cout<< "caught: "<< e.what()<< std::endl;
	}

	try{
		Bureaucrat obj("lili",1);
		Form o("mimi",2,45);
		std::cout<<obj<<std::endl;
		o.beSigned(obj);
		obj.signForm(o);
	}
	catch(std::exception &e)
	{
		std::cout<<"caught: "<< e.what()<< std::endl;
	}

    return 0;
}

#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"

int main(){

	try{
		std::cout<< "//////////*****Shrubbery*******\\\\\\\\\\\\\\\\"<<std::endl;
		Bureaucrat o("wei",137);
		ShrubberyCreationForm obj("mimi");
		std::cout<<"sign "<<obj.getSignGrade()<<" exec grade:  "<<obj.getExecGrade()<<std::endl;
		o.executeForm(obj);
		o.signForm(obj);
		o.executeForm(obj);
	}
	catch(std::exception &e)
	{
		std::cout<< "caught: "<< e.what();
	}
	try{
		std::cout<< "//////////*****Presidential*******\\\\\\\\\\\\\\\\"<<std::endl;
		Bureaucrat o("wei",2);
		PresidentialPardonForm obj("home");
		std::cout<<"sign "<<obj.getSignGrade()<<" exec grade:  "<<obj.getExecGrade()<<std::endl;
		o.executeForm(obj);
		o.signForm(obj);
		o.executeForm(obj);
	}
	catch(std::exception &e)
	{
		std::cout<< "caught: "<< e.what();
	}	
	try{
		std::cout<< "//////////*****robot*******\\\\\\\\\\\\\\\\"<<std::endl;
		Bureaucrat o("wei",10);
		RobotomyRequestForm obj("kiko");
		std::cout<<"sign "<<obj.getSignGrade()<<" exec grade:  "<<obj.getExecGrade()<<std::endl;
		o.executeForm(obj);
		o.signForm(obj);
		o.executeForm(obj);
	}
	catch(std::exception &e)
	{
		std::cout<< "caught: "<< e.what();
	}
    return 0;
}

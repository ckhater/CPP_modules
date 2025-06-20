#include"Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void){
    std::cout<< "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(void):name("anonyme"), grade(1337){
	throw Bureaucrat::GradeTooLowException();	
    std::cout<< "Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &br):name(br.name){
	std::cout<< "Bureaucrat copy constructor called\n";
	*this = br;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &br){
	std::cout<< "Bureaucrat copy assignement called\n";
	this->grade = br.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(std::string n, int g):name(n), grade(g){
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout<< "Bureaucrat constructor called\n";
}

std::string	Bureaucrat::getName(void)const{
	return this->name;
}

int		Bureaucrat::getGrade(void)const{
	return this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Too bad the grade is too high!\nThe highest grade is 1 don't pass it";
}

const char* Bureaucrat::GradeTooLowException::what()const throw(){
	return "Too bad the grade is too low!\nThe lowest grade is 150 don't pass it";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &br){
	out<< br.getName()<< ", bureaucrat grade "<<br.getGrade();
	return out;
}

void	Bureaucrat::IncrementGrade(void){
	grade--;
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::DecrementGrade(void){
	grade++;
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < 1)
		throw Bureaucrat::GradeTooHighException();

}

void	Bureaucrat::signForm(Form &fm){
	try{
		fm.beSigned(*this);
		std::cout<< name<< " signed "<< fm.getName()<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cout<< name<< " couldn't sign because it is lower than "<< fm.getSignGrade()<< std::endl;
	}
}

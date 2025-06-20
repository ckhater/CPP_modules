#include"Form.hpp"

Form::Form(void):name("anonyme"), signGrade(1337), execGrade(1337){
	issign = false;
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	std::cout<< "Form constructor called\n";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Too bad the grade is higher than the required one!\n";
}

const char* Form::GradeTooLowException::what()const throw(){
	return "Too bad the grade is lower than the required one!\n";
}

Form::Form(std::string n, int sign, int exec):name(n), signGrade(sign), execGrade(exec){
	issign = false;
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();		
	std::cout<< "Form constructor called\n";
}

Form::Form(Form const &fm):name(fm.name), signGrade(fm.signGrade), execGrade(fm.execGrade){
	std::cout<< "Form copy constructor called\n";
	*this = fm;
}

Form	&Form::operator=(Form const &fm){
	std::cout<< "Form copy assignement called\n";
	this->issign = fm.issign;
	return *this;
}  

Form::~Form(void){
	std::cout<< "Form destructor called\n";
}

int Form::getExecGrade(void)const{
	return this->execGrade;
}

bool Form::getIssign(void)const{
	return this->issign;
}

int	Form::getSignGrade(void)const{
	return this->signGrade;
}

std::string Form::getName(void)const{
	return this->name;
}

std::ostream &operator<<(std::ostream &out, Form const &fm){
	out<< fm.getName()<< ", Form sign grade is: "<<fm.getSignGrade()
	   <<" Form execute grade is: "<<fm.getExecGrade();
	return out;
}

void	Form::beSigned(Bureaucrat const &br){
	if(br.getGrade() <= signGrade)
		issign = true;
	else
		throw Form::GradeTooLowException();
}

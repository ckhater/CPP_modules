#include"AForm.hpp"

AForm::AForm(void):name("anonyme"), signGrade(1337), execGrade(1337){
	issign = false;
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	std::cout<< "AForm constructor called\n";
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Too bad the grade is higher than the required one!\n";
}

const char* AForm::GradeTooLowException::what()const throw(){
	return "Too bad the grade is lower than the required one!\n";
}

AForm::AForm(std::string n, int sign, int exec):name(n), signGrade(sign), execGrade(exec){
	issign = false;
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();		
	std::cout<< "AForm constructor called\n";
}

AForm::AForm(AForm const &fm):name(fm.name), signGrade(fm.signGrade), execGrade(fm.execGrade){
	std::cout<< "AForm copy constructor called\n";
	*this = fm;
}

AForm	&AForm::operator=(AForm const &fm){
	std::cout<< "AForm copy assignement called\n";
	this->issign = fm.issign;
	return *this;
}  

AForm::~AForm(void){
	std::cout<< "AForm destructor called\n";
}

int AForm::getExecGrade(void)const{
	return this->execGrade;
}

bool AForm::getIssign(void)const{
	return this->issign;
}

int	AForm::getSignGrade(void)const{
	return this->signGrade;
}

std::string AForm::getName(void)const{
	return this->name;
}

std::ostream &operator<<(std::ostream &out, AForm const &fm){
	out<< fm.getName()<< ", AForm sign grade is: "<<fm.getSignGrade()
	   <<" AForm execute grade is: "<<fm.getExecGrade();
	return out;
}

void	AForm::beSigned(Bureaucrat &br){
	if(br.getGrade() <= signGrade)
		issign = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor)const{
	
	if(issign && executor.getGrade() < execGrade)
		return ;
	else
		throw AForm::GradeTooLowException();
}

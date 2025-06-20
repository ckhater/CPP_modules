#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include<exception>
#include"AForm.hpp"

class AForm;

class Bureaucrat{
    private:
        const std::string  name;
        int grade;
    public:
		class GradeTooHighException: public std::exception{
			public:
				const char* what()const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char* what()const throw();
		};
        Bureaucrat(void);
        Bureaucrat(std::string n, int g);
        Bureaucrat(Bureaucrat const & br);
        Bureaucrat& operator=(Bureaucrat const &br);
        ~Bureaucrat(void);
        int			getGrade(void)const;
		std::string	getName(void)const;
		void	IncrementGrade(void);
		void	DecrementGrade(void);
		void	signForm(AForm &fm);
		void	executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &br);

#endif

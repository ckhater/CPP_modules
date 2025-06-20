#ifndef FORM_HPP
#define FORM_HPP

#include"Bureaucrat.hpp"

class Bureaucrat;
class Form{
	private:
		const std::string name;
		bool		issign;
		const int	signGrade;
		const int	execGrade;
	public:
        class GradeTooHighException:public std::exception{
            public:
                const char* what()const throw();
        };
        class GradeTooLowException:public std::exception{
            public:
                const char* what()const throw();
        };
		Form(std::string n, int sign, int exec);
		Form(void);
        Form(Form const &fm);
        Form& operator=(Form const &fm);
		~Form(void);
        int getSignGrade(void)const;
        int getExecGrade(void)const;
        bool getIssign(void)const;
        std::string getName(void)const;
        void    beSigned(Bureaucrat const &br);
};

std::ostream &operator<<(std::ostream &out, Form const &fm);
#endif

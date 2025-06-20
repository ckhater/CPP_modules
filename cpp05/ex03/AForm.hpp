#ifndef AForm_HPP
#define AForm_HPP

#include"Bureaucrat.hpp"

class Bureaucrat;
class AForm{
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
		AForm(std::string n, int sign, int exec);
		AForm(void);
        AForm(AForm const &fm);
        AForm& operator=(AForm const &fm);
		virtual ~AForm(void) = 0;
        int getSignGrade(void)const;
        int getExecGrade(void)const;
        bool getIssign(void)const;
        std::string getName(void)const;
        void    beSigned(Bureaucrat  &br);
        void execute(Bureaucrat const & executor)const;
};

std::ostream &operator<<(std::ostream &out, AForm const &fm);
#endif

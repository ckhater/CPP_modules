Name= intern
Flag= -std=c++98 -Wall -Wextra -Werror 
Src= main.cpp Bureaucrat.cpp AForm.cpp  PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
Obj= $(Src:.cpp=.o)

all:$(Name)

%.o : %.cpp
	c++ $(Flag) -c $< 

$(Name) : $(Obj)
	c++ $(Flag) $^ -o $@


clean:
	rm -rf $(Obj)

fclean: clean
	rm -rf $(Name)

re : fclean all

.PHONY: all clean fclean re
.SECONDARY: $(Obj)

Name= PmergeMe
Flag= -std=c++98 -Wall -Wextra -Werror 
Src= main.cpp  PmergeMe.cpp
Obj=$(Src:.cpp=.o)

all: $(Name)

%.o : %.cpp
	c++ $(Flag) -c $^ -o $@

$(Name): $(Obj)
	c++ $(Flag) $^ -o $@

clean:
	rm -rf $(Obj)

fclean: clean
	rm -rf $(Name)

re : fclean all

.PHONY: all clean fclean re

.SECONDARY: $(Obj)
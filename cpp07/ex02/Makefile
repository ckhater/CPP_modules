Name = template
Path = -I .
Flag = -std=c++98 -Wall -Wextra -Werror -g3 
Src = main.cpp
Obj = $(Src:.cpp=.o)

all: $(Name)


%.o : %.cpp
	c++ $(Path) $(Flag) -c $<

$(Name) : $(Obj)
	c++ $(Path) $(Flag) $^ -o $@
clean :
	rm -rf $(Obj)

fclean :clean
	rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY:$(Obj)

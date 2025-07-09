Name=span
Flag= -std=c++98 -Wall -Wextra -Werror
Src=main.cpp Span.cpp
Obj=$(Src:.cpp=.o)

all:$(Name)

$(Name) : $(Obj)
	c++ $(Flag) $^ -o $@

%.o : %.cpp
	c++ $(Flag) -c $< -o $@

clean:
	rm -rf $(Obj)

fclean:clean
	rm -rf $(Name)

re: fclean all

.PHONY:all clean fclean re
.SECONDARY:$(Obj)
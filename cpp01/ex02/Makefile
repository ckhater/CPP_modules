NAME= brain
FLAG= -std=c++98 -Wall -Wextra -Werror
SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

%.o : %.cpp
	c++ $(FLAG) $< -c

$(NAME): $(OBJ)
	c++ $(FLAG) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)
re: fclean all
.PHONY: clean fclean re all
.SECONDARY: $(OBJ)

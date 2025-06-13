NAME=brainz
FLAG=-std=c++98 -Wall -Wextra -Werror
SRC=main.cpp newZombie.cpp Zombie.cpp randomChump.cpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	c++ $(CFLAG) $< -c -o $@

$(NAME) : $(OBJ)
	c++ $(CFLAG) $^ -o $@

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)

re :fclean all
.PHONY: clean fclean re all
.SECONDARY: $(OBJ)

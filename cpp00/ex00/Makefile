NAME = megaphone
SRC = megaphone.cpp
FLAG = -std=c++98 -Wall -Wextra -Werror
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	c++ $(FLAG) -c $< 

$(NAME): $(OBJ)
	c++ $(FLAG) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

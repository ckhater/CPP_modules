NAME = Account
FLAG= -std=c++98 -Wall -Wextra -Werror
SRC=Account.cpp tests.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	c++ $(FLAG) -c $< 

$(NAME): $(OBJ)
	c++ $(FLAG) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
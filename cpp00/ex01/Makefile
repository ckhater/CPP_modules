NAME=phonebook
FLAG= -std=c++98 -Wall -Wextra -Werror
SRC=main.cpp Contact.cpp PhoneBook.cpp
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

Name=animal
FLAG= -std=c++98 -Wall -Wextra -Werror
SRC= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp
OBJ=$(SRC:.cpp=.o)

all:$(Name)

%.o: %.cpp
	c++ $(FLAG) -c $< -o $@

$(Name): $(OBJ)
	c++ $(FLAG) $(OBJ) -o $(Name)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)
re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)


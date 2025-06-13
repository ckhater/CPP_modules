Name=interface
FLAG= -std=c++98 -Wall -Wextra -Werror -g3
SRC= main.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp AMateria.cpp
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


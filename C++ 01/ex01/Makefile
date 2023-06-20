NAME		= Horde
SRC			= main.cpp Zombie.cpp zombieHorde.cpp
FLAGS		= -Wall -Wextra -Werror
COMPILER	= g++

all : $(NAME)

$(NAME) : $(SRC)
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean	: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
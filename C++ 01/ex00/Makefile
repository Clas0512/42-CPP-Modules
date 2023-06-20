NAME		= Zombie
SRC			= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
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
NAME	= megaphone
SRC		= megaphone.cpp
FLAGS	= -Wall -Wextra -Werror
COMPILE	= g++

all : $(NAME)

$(NAME) :
	@$(COMPILE) $(FLAGS) $(SRC) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean	: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

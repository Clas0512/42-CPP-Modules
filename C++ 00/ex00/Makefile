NAME		= megaphone
SRC			= megaphone.cpp
FLAGS		= -Wall -Wextra -Werror
COMPILER	= g++

all : $(NAME)

$(NAME) :
	@$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean	: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

NAME		= Brain

SRC			= main.cpp

COMPILER	= c++

FLAGS		= -Wall -Wextra -Werror -std=c++98

all	: $(NAME)

$(NAME) : $(SRC)
	$(COMPILER) $(SRC) $(FLAGS) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean	: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

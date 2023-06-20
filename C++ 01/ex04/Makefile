NAME		= 

SRC			= main.cpp

COMPILER	= g++

FLAGS		= -Wall -Wextra -Werror

all	: $(NAME)

$(NAME) : $(SRC)
	$(COMPILER) $(SRC) $(FLAGS) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean	: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

NAME		= harlFilter

SRC			= main.cpp Harl.cpp

COMPILER	= g++

FLAGS		= -Wall -Wextra -Werror

all	: $(NAME)

$(NAME) : $(SRC)
	@$(COMPILER) $(SRC) $(FLAGS) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean	: clean

re : clean all

.PHONY : all clean fclean re

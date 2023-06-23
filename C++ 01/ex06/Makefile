NAME		= harlFilter

SRC			= main.cpp Harl.cpp

COMPILER	= c++

FLAGS		= -Wall -Wextra -Werror -std=c++98

all	: $(NAME)

$(NAME) : $(SRC)
	@$(COMPILER) $(SRC) $(FLAGS) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean	: clean

re : clean all

.PHONY : all clean fclean re

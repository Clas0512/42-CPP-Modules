NAME	= PhoneBook
SRC		= main.cpp PhoneBook.cpp Contact.cpp
FLAGS	= -Wall -Wextra -Werror
COMPILE	= g++

all : $(NAME)

$(NAME) :
	@$(COMPILE) $(FLAGS) $(SRC) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean : clean
	@rm -rf Contact.hpp.gch
	@rm -rf PhoneBook.hpp.gch

re : fclean all

.PHONY : all clean fclean re

NAME	= RPN

SRCS	= $(wildcard *.cpp)

CC		= c++

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -Wall -Wextra -Werror -std=c++98

all	: $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(NAME)

fclean : clean
	@rm -rf *.o

re	: fclean all

.PHONY : all fclean clean re
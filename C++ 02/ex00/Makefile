NAME = Fixed

SRCS = Fixed.cpp main.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

git: fclean
	git add .
	git commit -m "auto commit"
	git push

re: fclean all

.PHONY: all clean fclean re

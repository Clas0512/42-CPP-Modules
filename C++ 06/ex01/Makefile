NAME		= Serialize

SRCS		= main.cpp Serializer.cpp

COMPILER	= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(SRCS)
	@$(COMPILER) $(SRCS) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean re
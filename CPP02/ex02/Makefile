NAME = fixed

SRCS = Fixed.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJS)

re : fclean all

.PHONY : all re fclean clean

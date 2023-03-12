NAME = myzombies

SRCS = Zombie.cpp main.cpp zombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

re : fclean all

fclean :
	rm -rf $(OBJS) $(NAME)

clean :
	rm -rf $(OBJS)

.PHONY : all re fclean clean

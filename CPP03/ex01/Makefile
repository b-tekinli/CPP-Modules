NAME = ScavTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS = $(SRCS:%.cpp= %.o)

CFAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

C++ = c++

all : $(NAME)

$(NAME) : $(OBJS)
	$(C++) $(CFLAGS) $(SRCS) -o $(NAME) -std=c++98

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY = all clean fclean re

NAME = Interface

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

CFAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:%.cpp= %.o)

RM = rm -rf

C++ = c++

all : $(NAME)

$(NAME) : $(OBJS)
	$(C++) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY = all clean fclean re

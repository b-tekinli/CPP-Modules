NAME = Animal

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

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

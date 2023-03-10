NAME = megaphone

C++ = c++

O = -o

SRCS = megaphone.cpp

OBJ = $(SRCS:.cpp=.o)

GFLAG = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJ)
	$(C++) $(GFLAG) $(SRCS) $(O) $(NAME) -std=c++98

.o : .cpp
	$(C++) -c $^ -o $@

fclean :
		rm -rf $(NAME) *.o

clean :
	*.o

re : fclean all

.PHONY : all fclean clean

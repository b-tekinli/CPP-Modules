NAME = phone

C++ = c++

OBJ = $(SRCS:.cpp=.o)

SRCS =  Contact.cpp Phonebook.cpp main.cpp

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(C++) $(SRCS) $(CFLAGS) -o $(NAME) -std=c++98

.o : .cpp
	$(c++) -c $^ -o $@

re : fclean all

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(OBJ) $(NAME)

.PHONY : all clean re fclean

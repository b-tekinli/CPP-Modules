NAME = Harl

CFLAG = -Wall -Wextra -Werror

OBJ = $(SRC:%.cpp=%.o)

SRC = Harl.cpp main.cpp


all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CFLAG) $(SRC) -o $(NAME) -std=c++14

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

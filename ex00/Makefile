CC = c++ 
CFLAG =  -std=c++98 -Wall -Wextra -Werror -g  
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

OUT = btc

all : $(OUT)

$(OUT) : $(OBJ) 
	$(CC) $(OBJ) -o $(OUT)

obj/%.o : %.cpp *.hpp
	@mkdir -p obj
	$(CC) $(CFLAG)  -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean 
	rm -rf $(OUT)
re : fclean all
NAME = Zombie

CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror


RM = rm
RMFLAG = -f

SRCS = main.cpp \
		Zombie.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

bonus: all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean run fclean re
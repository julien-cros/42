# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:56:15 by juliencros        #+#    #+#              #
#    Updated: 2023/05/04 09:54:39 by juliencros       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

SRCS = \
	main.c \
	parsing.c \
	valid_map.c \
	display.c \
	errors.c \
	utils.c \
	mem.c \
	check_finishable.c \
	
INCLUDES =	./struct.h \
			./parsing.h \
			./valid_map.h \
			./display.h \
			./errors.h \
			./mem.h \
			./utils.h \
			./check_finishable.h \
			


	

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) # $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(RMFLAG) $(OBJS)

# compile: $(NAME)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean run fclean re 
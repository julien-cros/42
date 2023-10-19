# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:56:15 by juliencros        #+#    #+#              #
#    Updated: 2023/10/19 11:30:16 by juliencros       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

SRCS = \
	main.c \
	init.c\
	int.c \
	error.c \
	free.c \
	threads.c \
	eat.c \
	sleep_think.c \
	time.c \
	exit.c \
	action.c \
	ft_print.c \
	parse.c \

INCLUDES =	\

PTHREAD = -pthread

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) # $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PTHREAD)

clean:
	$(RM) $(RMFLAG) $(OBJS)

# compile: $(NAME)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)
	$(RM) $(RMFLAG) .error_fd

re: fclean all

.PHONY: all clean run fclean re 
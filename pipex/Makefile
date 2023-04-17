# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:56:15 by juliencros        #+#    #+#              #
#    Updated: 2023/04/17 21:07:15 by juliencros       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

SRCS = \
	main.c \
	parsing.c \
	utils.c \
	strs.c \
	display.c \
	here_doc.c \
	free.c \
	split.c \
	files.c \
	error.c \
	ft_pipex.c \

INCLUDES =	./utils.h \
			./struct.h \
			./strs.h \
			./parsing.h \
			./display.h \
			./here_doc.h \
			./free.h \
			./split.h \
			./files.h \
			./error.h \
			./ft_pipex.h \

	

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
	$(RM) $(RMFLAG) .here_doc_fd
	$(RM) $(RMFLAG) .error_fd

re: fclean all

.PHONY: all clean run fclean re 
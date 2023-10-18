# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 21:43:09 by herbie            #+#    #+#              #
#    Updated: 2023/10/18 09:33:51 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = #-Wall -Wextra -Werror

RM = rm
RMFLAG = -f

SRCS = \
	main.c \
	mem.c \
	str.c \
	print.c \
	display.c \
	history.c \
	signals.c \
	str2.c \
	free.c \
	fd.c \
	init.c \
	int.c \
	shell_levels.c \
	env.c \
	lexer.c \
	token.c \
	char.c \
	lexer_utils.c \
	error.c \
	get_line.c \
	here_doc.c \
	find.c \
	execution.c \
	find_cmd.c \
	split.c \
	args.c \
	path_args.c \
	builtin.c \
	builtins_func.c \
	echo.c \
	export.c \
	parse.c \
	redirection.c \
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(shell pkg-config --cflags readline)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(shell pkg-config --libs readline)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean run fclean re

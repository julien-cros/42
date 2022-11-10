# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 12:44:32 by jcros             #+#    #+#              #
#    Updated: 2022/11/10 14:38:30 by juliencros       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INCLUDES = ./libft.h

SRCS= \
	./ft_memset.c       \
	./ft_bzero.c        \
	./ft_strlen.c       \
	./ft_isalpha.c      \
	./ft_isalnum.c      \
	./ft_isascii.c      \
	./ft_isprint.c      \
	./ft_isdigit.c      \
	./ft_memcpy.c       \
	./ft_memmove.c      \
	./ft_strlcpy.c      \
	./ft_strlcat.c      \
	./ft_toupper.c      \
	./ft_tolower.c	    \
	./ft_strchr.c       \
	./ft_memchr.c       \
	./ft_strrchr.c      \
	./ft_strncmp.c      \
	./ft_memcmp.c       \
	./ft_strnstr.c      \
	./ft_atoi.c         \
	./ft_strdup.c       \
	./ft_calloc.c       \
	# ./ft_substr.c       \
	# ./ft_strjoin.c      \
	# ./ft_strtrim.c      \
	# ./ft_split.c        \
	# ./ft_itoa.c         \
	# ./ft_strmapi.c      \
	# ./ft_putchar_fd.c   \
	# ./ft_putstr_fd.c    \
	# ./ft_putendl_fd.c   \
	# ./ft_putnbr_fd.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 12:44:32 by jcros             #+#    #+#              #
#    Updated: 2022/11/15 13:04:42 by juliencros       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

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
	./ft_substr.c       \
	./ft_strjoin.c      \
	./ft_strtrim.c      \
	./ft_split.c        \
	./ft_itoa.c         \
	# ./ft_strmapi.c      \
	# ./ft_putchar_fd.c   \
	# ./ft_putstr_fd.c    \
	# ./ft_putendl_fd.c   \
	# ./ft_putnbr_fd.c

# BONUS_SRC = \
# 	ft_lstlew.c			\
# 	ft_lstadd_front.c	\	
# 	ft_lstsize.c		\
# 	ft_lstlast.c		\
# 	ft_lstadd_back.c	\
# 	ft_lstdelone.c		\
# 	ft_lstclear.c		\
# 	ft_lstiter.c		\
# 	ft_lstmap.c			\

OBJS = $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)


# bonus: $(BONUS_OBJS) $(NAME)
# 	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

.c.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re
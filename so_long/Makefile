# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:56:15 by juliencros        #+#    #+#              #
#    Updated: 2023/05/11 13:27:36 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

RM = rm
RMFLAG = -f

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

SRCS = \
	main.c \
	valid_map.c \
	display.c \
	errors.c \
	utils.c \
	mem.c \
	find_valid.c \
	free.c \

OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)
	@make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean run fclean re 

# NAME = so_long

# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# RM = rm
# RMFLAG = -f

# SRCS = \
# 	main.c \
# 	parsing.c \
# 	valid_map.c \
# 	display.c \
# 	errors.c \
# 	utils.c \
# 	mem.c \
# 	check_finishable.c \
# 	find_valid.c

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# bonus: all

# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# $(NAME): $(OBJS) # $(INCLUDES)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# clean:
# 	$(RM) $(RMFLAG) $(OBJS)

# # compile: $(NAME)
# # 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# fclean: clean
# 	$(RM) $(RMFLAG) $(NAME)

# re: fclean all

# .PHONY: all clean run fclean re %
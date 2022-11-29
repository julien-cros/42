# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcros <jcros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 12:44:32 by jcros             #+#    #+#              #
#    Updated: 2022/11/18 10:27:30 by jcros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = cc
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
	./ft_strmapi.c      \
	./ft_striteri.c		\
	./ft_putchar_fd.c   \
	./ft_putstr_fd.c    \
	./ft_putnbr_fd.c	\
	./ft_putendl_fd.c

BONUS_SRCS= \
	./ft_lstnew.c        \
	./ft_lstsize.c       \
	./ft_lstadd_front.c  \
	./ft_lstlast.c       \
	./ft_lstadd_back.c   \
	./ft_lstdelone.c     \
	./ft_lstclear.c      \
	./ft_lstiter.c       \
	./ft_lstmap.c


OBJS        =        $(SRCS:.c=.o)

$(NAME):	$(OBJS)
		@$(AR) $(ARFLAGS) $@ $^

.c.o:		$(SRCS) $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@)$(COM_COLOR)]\n";
	
all:	$(NAME)
	@printf "%b" "$(COM_COLOR)#######################################$(NO)\n"
	@printf "%b" "$(OK_COLOR)      *¤ * * ¤* * ¤*          *¤ * *¤ *$(NO)\n"
	@printf "%b" "$(OK_COLOR)   ¤* ** *¤  * *¤          ** * ¤ * ¤ ¤$(NO)\n"
	@printf "%b" "$(OK_COLOR)¤* ¤ *  *¤  **   $(OK_COLOR)$(OK_STRING)$(OK_COLOR)   ¤* * *¤ ¤* ¤*  $(NO)\n"
	@printf "%b" "$(OK_COLOR)*  * ¤*  ¤*          ¤* * ¤  * * ¤*    $(NO)\n"
	@printf "%b" "$(OK_COLOR)* ¤ *¤*          ** ¤ * * ¤ *¤*        $(NO)\n"
	@printf "%b" "$(COM_COLOR)#######################################$(NO)\n"
	@printf "%b" "$(MESSAGE_COLOR)[Compilation completed]\n"

clean:
			@rm -f $(OBJS)
			@printf "%b" "$(CLEAN_COLOR)#######################################\n"
			@printf "%b" "$(CLEAN_COLOR)$(CLEAN_STRING)$(OBJ_COLOR) all$(CLEAN_COLOR)]\n";
			@printf "%b" "$(CLEAN_COLOR)#######################################\n"
			@printf "%b" "$(OK_COLOR)      *¤ * * ¤* * ¤*          *¤ * *¤ *\n"
			@printf "%b" "$(OK_COLOR)   ¤* ** *¤  * *¤          ** * ¤ * ¤ ¤\n"
			@printf "%b" "¤* ¤ *  *¤  **   $(OK_COLOR)$(OK_STRING)   ¤* * *¤ ¤* ¤ *\n"
			@printf "%b" "$(OK_COLOR)*  * ¤*  ¤*          ¤* * ¤  * * *¤    \n"
			@printf "%b" "$(OK_COLOR)* ¤ *¤*          ** ¤ * * ¤ *¤*        \n"
			@printf "%b" "$(CLEAN_COLOR)#######################################\n\n"
			@printf "%b" "$(MESSAGE_COLOR)[Cleaning completed]\n"

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

COM_COLOR = \033[0;32m
OBJ_COLOR = \033[0;45m
OK_COLOR  = \033[0;44m
CLEAN_COLOR  = \033[0;33m
MESSAGE_COLOR = \033[0;33m
NO = \033[0;0m

OK_STRING = "[OK]"
COM_STRING = "[Compiling"
CLEAN_STRING = "[Cleaning"

.PHONY: all clean fclean re

# OBJS = $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# all: $(NAME)

# bonus: $(BONUS_OBJS) $(NAME)
# 	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

# .c.o: $(SRCS) $(INCLUDES)
# 	$(CC) $(CFLAGS) -c $< -o $(<:.c=.cd o)

# clean:
# 	$(RM) $(RMFLAG) $(OBJS) $(BONUS_OBJS)

# fclean: clean
# 	$(RM) $(RMFLAG) $(NAME)

# re: fclean all

# $(NAME): $(OBJS)
# 	$(AR) $(ARFLAGS) $@ $^

# .PHONY: all clean fclean re
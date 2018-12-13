# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboucher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 14:46:57 by bboucher          #+#    #+#              #
#    Updated: 2018/12/13 12:09:50 by bboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OK_COLOR = \033[32m
NO_COLOR = \033[m

OK = $(OK_COLOR)OK$(NO_COLOR)

NAME = fillit

IDIR = -Iincludes/ -Ilibft/includes

SRC =  main.c \
	   map.c \
	   reader.c \
	   check_error.c \
	   parser.c \
	   backtracking.c \
	   placement.c \
	   del_struct.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/ fclean && make -C libft/
	@$(CC) -o $(NAME) $(IDIR) $(OBJ) libft/libft.a
	@echo "[fillit] | Compilation						$(OK)"

%.o: %.c
	@$(CC) $(CFLAGS) $(IDIR) -o $@ -c $<

clean :
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@echo "[fillit] | clean						$(OK)"

fclean : clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "[fillit] | fclean						$(OK)"

re : fclean all

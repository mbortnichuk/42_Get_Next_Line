# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 11:46:30 by mbortnic          #+#    #+#              #
#    Updated: 2017/12/08 12:06:11 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CFLAGS = -Wall -Wextra -Werror

CC = clang

INC = get_next_line.h libft.h

SRC = get_next_line.c mainmain.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@ echo "\033[32;1mget_next_line ready to go\033[0m"

$(OBJ): $(LIBFT)
	$(CC) $(CFLAGS) -c $(SRC)

$(LIBFT): lib

lib: 
	make -C libft

clean:
	$(RM) $(OBJ)
	make clean -C ./libft/
	@ echo "\033[33;1mobj files are removed\033[0m"

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft/
	@ echo "\033[31;1m$(NAME) is deleted\033[0m"

re: fclean all
	@ echo "\033[36;1mre is performed\033[0m"

norm:
	@ echo "\033[35;1mstarting look for norme errors...\033[0m"
	norminette *.c *.h
	@ echo "\033[35;1mnorminette check finished\033[0m"

.PHONY: all re clean fclean norm



# 	'$(NAME): $(LIB) $(OBJ) $(INC)
#     $(CC) $(CFLAGS) -o $(NAME) $(LIB) $(OBJ)

# lib:
#     make -C libft

# $(LIB): lib
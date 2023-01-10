# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 17:57:43 by elukutin          #+#    #+#              #
#    Updated: 2023/01/10 18:00:31 by elukutin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = int_algs.c main.c rules.c stack_algs.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) libft/libft.a $(CFLAGS) -o $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

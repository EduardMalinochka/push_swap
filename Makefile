# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 17:57:43 by elukutin          #+#    #+#              #
#    Updated: 2023/01/12 21:43:46 by elukutin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = int_algs.c main.c rules.c stack_algs.c utils.c stack_utils.c main_steps.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = checker.c checker_rules.c stack_utils.c int_algs.c utils.c main_steps.c
B_OBJS = $(BONUS_SRC:.c=.o)

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

bonus: $(BONUS)	
	
$(BONUS): $(B_OBJS)
	make -C libft
	$(CC) $(B_OBJS) libft/libft.a $(CFLAGS) -o $(BONUS)
	
.PHONY: all clean fclean re

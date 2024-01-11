# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:58:40 by tjoyeux           #+#    #+#              #
#    Updated: 2024/01/12 00:06:00 by tjoyeux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_PATH = srcs
LIBFT_PATH = libft
SRC = srcs/algo.c srcs/algo_utils.c srcs/counting.c srcs/data_structure.c srcs/indexation.c srcs/instructions.c srcs/main.c srcs/memory.c srcs/parsing.c srcs/push.c srcs/rev_rotate.c srcs/rotate.c srcs/swap.c srcs/value_updater.c
#SRC = $(wildcard $(SRC_PATH)/*.c)
OBJ = $(SRC:.c=.o)
NAME = push_swap
RM = rm -f
LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./$(LIBFT_PATH) -lft

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(LIBFT) : $(LIBFT_PATH)/Makefile
	@echo "Avant de faire 'make' dans libft"
	make -C $(LIBFT_PATH)
	@echo "Apres avoir fait 'make' dans libft"
 
clean :
	$(RM) $(SRC_PATH)/*.o
	make clean -C $(LIBFT_PATH)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re

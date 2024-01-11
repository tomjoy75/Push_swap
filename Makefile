# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:58:40 by tjoyeux           #+#    #+#              #
#    Updated: 2024/01/11 18:11:36 by tjoyeux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_PATH = srcs
LIBFT_PATH = libft
SRC = $(wildcard $(SRC_PATH)/*.c)
OBJ = $(SRC:.c=.o)
NAME = push_swap
RM = rm -f
LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./$(LIBFT_PATH) -lft

$(OBJ) : $(SRC) push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(LIBFT) : $(LIBFT_PATH)/Makefile
	make all -C $(LIBFT_PATH)
 

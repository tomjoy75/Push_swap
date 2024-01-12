# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:58:40 by tjoyeux           #+#    #+#              #
#    Updated: 2024/01/12 17:51:24 by tjoyeux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(LIBFT_PATH) -lft
RM = rm -f

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/

SRC = $(wildcard $(SRC_PATH)*.c)
OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(LIBFT) : $(LIBFT_PATH)/Makefile
	@echo "Avant de faire 'make' dans libft"
	make -C $(LIBFT_PATH)
	@echo "Apres avoir fait 'make' dans libft"
 
clean :
	$(RM) $(SRC_PATH)*.o
	make clean -C $(LIBFT_PATH)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

c :  push_swap.h
	$(CC) $(CFLAGS) -c -I. -g3 -fsanitize=address $(SRC) 

.PHONY : all clean fclean re c

define START

  ██████ ▄▄▄█████▓ ▄▄▄       ██▀███  ▄▄▄█████▓
▒██    ▒ ▓  ██▒ ▓▒▒████▄    ▓██ ▒ ██▒▓  ██▒ ▓▒
░ ▓██▄   ▒ ▓██░ ▒░▒██  ▀█▄  ▓██ ░▄█ ▒▒ ▓██░ ▒░
  ▒   ██▒░ ▓██▓ ░ ░██▄▄▄▄██ ▒██▀▀█▄  ░ ▓██▓ ░
▒██████▒▒  ▒██▒ ░  ▓█   ▓██▒░██▓ ▒██▒  ▒██▒ ░
▒ ▒▓▒ ▒ ░  ▒ ░░    ▒▒   ▓▒█░░ ▒▓ ░▒▓░  ▒ ░░
░ ░▒  ░ ░    ░      ▒   ▒▒ ░  ░▒ ░ ▒░    ░
░  ░  ░    ░        ░   ▒     ░░   ░   ░
      ░                 ░  ░   ░

endef
export START

define LIBFT_HEADER



 ██▓     ██▓ ▄▄▄▄     █████▒▄▄▄█████▓
▓██▒    ▓██▒▓█████▄ ▓██   ▒ ▓  ██▒ ▓▒
▒██░    ▒██▒▒██▒ ▄██▒████ ░ ▒ ▓██░ ▒░
▒██░    ░██░▒██░█▀  ░▓█▒  ░ ░ ▓██▓ ░
░██████▒░██░░▓█  ▀█▓░▒█░      ▒██▒ ░
░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒ ░      ▒ ░░
░ ░ ▒  ░ ▒ ░▒░▒   ░  ░          ░
  ░ ░    ▒ ░ ░    ░  ░ ░      ░
    ░  ░ ░   ░
                  ░

endef
export LIBFT_HEADER

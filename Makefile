# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:58:40 by tjoyeux           #+#    #+#              #
#    Updated: 2024/01/16 15:46:03 by tjoyeux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#________________________________Variables___________________________________
NAME = push_swap
NAME_BONUS = checker
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

CC		= gcc
CFLAGS		= -Wall -Werror -Wextra -g3
LDFLAGS		= -L$(LIBFT_PATH) -lft
RM		= rm -f

SRC_PATH	= ./srcs/
OBJ_PATH	= ./objs/
BONUS_PATH	= ./bonus/

COMMON_SRC	= $(filter-out $(SRC_PATH)main.c $(SRC_PATH)main_bonus.c, $(wildcard $(SRC_PATH)*.c))
SRC		= $(COMMON_SRC) $(SRC_PATH)main.c
SRC_BONUS	= $(COMMON_SRC) $(SRC_PATH)main_bonus.c
OBJ		= $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
OBJ_BONUS	= $(SRC_BONUS:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

FLAG_FILE	:= .build_started
FLAG_BONUS	:= .build_started_bonus
BUILD_FLAG	:= .build_done
#________________________________Push_Swap___________________________________

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ) push_swap.h
	@echo "$(GREEN)$(BOLD)$(ITALIC)$$LINKING$(RESET)\n"
	@echo "$(MAGENTA)$(BOLD)Linking: $(RESET)$(BLUE)$(ITALIC)$@$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

#_________________________________Checker____________________________________

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(OBJ_BONUS) push_swap.h
	@echo "$(GREEN)$(BOLD)$(ITALIC)$$LINKING$(RESET)\n"
	@echo "$(MAGENTA)$(BOLD)Linking: $(RESET)$(BLUE)$(ITALIC)$@$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LDFLAGS)

#____________________________Common operations_______________________________

$(LIBFT) : $(LIBFT_PATH)/Makefile
	@echo "$(GREEN)$(BOLD)$(ITALIC)$$LIBFT_HEADER$(RESET)\n"
	@echo "$(MAGENTA)$(BOLD)Libft Construction: $(BLUE)$(ITALIC)$(LIBFT)$(RESET)"
	make -C $(LIBFT_PATH)
	@echo "$(RESET)"
 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c push_swap.h
	@if [ ! -f $(FLAG_FILE) ]; then touch $(FLAG_FILE); echo "$(GREEN)$(BOLD)$$COMPILATION$(RESET)"; fi
	@mkdir -p $(@D)
#	@echo "$$COMPILATION\n"
	@echo "$(MAGENTA)$(BOLD)Compilation: $(RESET)$(BLUE)$(ITALIC)$<$(RESET)"
	$(CC) $(CFLAGS) -I. -c $< -o $@
	@touch $(BUILD_FLAG)

#________________________________Cleaning____________________________________
clean :
	@echo "$(GREEN)$(BOLD)$$CLEANING$(RESET)"
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(OBJ)$(RESET)"
	$(RM) $(OBJ_PATH)*.o
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(FLAG_FILE)$(RESET)"
	$(RM) .build_started
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(LIBFT_PATH)*.o$(RESET)"
	make clean -C $(LIBFT_PATH)

fclean : clean
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(LIBFT)$(RESET)"
	make fclean -C $(LIBFT_PATH)
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(NAME)$(RESET)"
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re : fclean all

##debug :  push_swap.h
##	$(CC) $(CFLAGS) -c -I. -g3 -fsanitize=address $(SRC) 

##debug_bonus :  push_swap.h
##	$(CC) $(CFLAGS) -c -I. -g3 -fsanitize=address $(SRC_BONUS) 

.PHONY : all clean fclean re debug debug_bonus

#______________________________Presentation__________________________________
# Colors
RED := \033[0;31m
GREEN := \033[0;32m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
RESET := \033[0m

# Style
BOLD := \033[1m
ITALIC := \033[3m
BLINK := \e[5m

define START


   ___| __ __|   \      _ \ __ __| 
 \___ \    |    _ \    |   |   |   
       |   |   ___ \   __ <    |   
 _____/   _| _/    _\ _| \_\  _|   
                                   


endef
export START

define LIBFT_HEADER


  |     _ _|  __ )   ____| __ __| 
  |       |   __ \   |        |   
  |       |   |   |  __|      |   
 _____| ___| ____/  _|       _|   
                                  

endef
export LIBFT_HEADER

define COMPILATION


   ___|   _ \    \  |   _ \ _ _|  |         \  __ __| _ _|   _ \    \  | 
  |      |   |  |\/ |  |   |  |   |        _ \    |     |   |   |    \ | 
  |      |   |  |   |  ___/   |   |       ___ \   |     |   |   |  |\  | 
 \____| \___/  _|  _| _|    ___| _____| _/    _\ _|   ___| \___/  _| \_| 
                                                                         


endef
export COMPILATION

define LINKING


  |     _ _|   \  |  |  / _ _|   \  |   ___| 
  |       |     \ |  ' /    |     \ |  |     
  |       |   |\  |  . \    |   |\  |  |   | 
 _____| ___| _| \_| _|\_\ ___| _| \_| \____| 


endef
export LINKING

define CLEANING


   ___|  |      ____|     \      \  | _ _|   \  |   ___|
  |      |      __|      _ \      \ |   |     \ |  |
  |      |      |       ___ \   |\  |   |   |\  |  |   |
 \____| _____| _____| _/    _\ _| \_| ___| _| \_| \____|

endef 
export CLEANING

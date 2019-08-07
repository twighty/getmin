# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 16:02:36 by akhmetsha         #+#    #+#              #
#    Updated: 2019/08/07 16:07:42 by akhmetsha        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getmin

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes -I./libft
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/

SRCS = $(SRCS_DIR)operations.c $(SRCS_DIR)main.c
SRCS_DIR = ./srcs/

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT)
		@$(CC) $(FLAGS) $(LIBFT) $(INCLUDES) $(SRCS) -o $(NAME)
		@echo "$(GREEN)$(NAME) has been created$(RESET)"
$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)
		@echo "$(NAME): $(GREEN)Assembling $(LIBFT)...$(RESET)"

clean:
		@$(MAKE) clean -C $(LIBFT_DIR)

fclean:
		@$(MAKE) fclean -C $(LIBFT_DIR)
		@rm -rf $(NAME)
		@echo "$(RED)$(NAME) executable has been deleted$(RESET)"

re:
		@$(MAKE) fclean
		@$(MAKE) all

.PHONY: all clean fclean re
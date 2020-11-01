# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 16:52:49 by gzoltan           #+#    #+#              #
#    Updated: 2020/08/13 18:50:01 by clynderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

# VARIABLES

HDRS = ./includes/ft_printf.h ./libft/includes/libft.h

INCLUDES = -I includes -I $(LIB_FT_DIR)

LIB_FT_DIR = ./libft/
LIB_FT_FILE = $(LIB_FT_DIR)/libft.a

OBJ_DIR = ./objects/
SRC_DIR = ./srcs/

C_FILES = $(shell find $(SRC_DIR) -type f -name '*.c')
O_FILES = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(C_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
OBJ_DIRS = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC_DIRS))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re FAKE

all: $(NAME)

$(NAME): $(OBJ_DIRS) $(O_FILES) $(LIB_FT_FILE)
	@make -C $(LIB_FT_DIR)
	@cp $(LIB_FT_FILE) $(NAME)
	@ar rc $(NAME) $(O_FILES)
	@echo "make: $(GREEN)💚Done building '$(NAME)'💚.$(RESET)"

$(OBJ_DIRS):
	@mkdir -vp $(OBJ_DIRS)

$(LIB_FT_FILE): FAKE
	@make -C $(LIB_FT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDRS)
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@make -C $(LIB_FT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "make: $(RED)💔Done clean of OBJ💔.$(RESET)"


fclean: clean
	@make -C $(LIB_FT_DIR) fclean
	@rm -f $(NAME)
	@echo "make: $(RED)💔Done clean of '$(NAME)'💔.$(RESET)"


re: fclean all

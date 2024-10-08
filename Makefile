# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconti <aconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 15:10:20 by aconti            #+#    #+#              #
#    Updated: 2024/07/31 15:56:55 by aconti           #+#    #+#              #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

# Source files
FREE = free_all/free_cub.c free_all/free_data.c
MATH = math/fmap.c
EVENTS = events/close.c events/some_mlx.c events/some_other_mlx.c events/moves.c 
WINDOW = window/my_pxl.c window/init_win.c window/minimap.c window/player_init.c window/init_cub.c window/sprites.c window/minimap2.c
PARSING = parsing/other_checks.c parsing/init_data.c parsing/check_continue.c parsing/other_init.c parsing/parsing_map.c parsing/map_checks.c parsing/check_matrix.c
MAIN = main.c
RAYCASTING = raycasting/sword.c raycasting/dda.c raycasting/dda2.c raycasting/raycasting.c raycasting/draw.c raycasting/raycasting2.c raycasting/draw2.c
GET_NEXT_LINE = includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c
LIBFT_DIR = includes/libft


PURPLE = '\033[0;35m'
GREEN = '\033[0;32m'
RED = '\033[0;31m'
NONE = '\033[0m'

# Libraries and include directories
LIBFT = $(LIBFT_DIR)/libft.a
MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = minilibx-linux
DEST_DIR = includes

# Compilation flags
FLAGS = -L$(DEST_DIR)/$(MLX_DIR) -lmlx -lX11 -lXext -lm -L$(LIBFT_DIR) -lft
MAKEFLAGS += --no-print-directory

COMPILE = gcc -Wall -Wextra -Werror -g

# Source and object files
SRCS = $(MAIN) $(WINDOW) $(PARSING) $(EVENTS) $(GET_NEXT_LINE) $(FREE) $(MATH) $(RAYCASTING)
OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Default target
all: $(DEST_DIR)/$(MLX_DIR) $(LIBFT) $(NAME)

# Cloning and setting up MinilibX
$(DEST_DIR)/$(MLX_DIR):
	@git clone $(MLX) $(DEST_DIR)/$(MLX_DIR) > /dev/null 2>&1
	@cd $(DEST_DIR)/$(MLX_DIR) && ./configure > /dev/null 2>&1
	@echo $(GREEN)"MinilibX Cloned! ✔️"$(NONE)
# Building libft
$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo $(RED)"Libft Compiled!	 ✔️"$(NONE)

# Linking the final executable
$(NAME): $(OBJS) $(LIBFT)
	@$(COMPILE) $(OBJS) $(FLAGS) -o $(NAME)
	@echo $(PURPLE)"Cub3d Compiled!	 ✔️"$(NONE)
# Compiling object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@

bonus: all

# Cleaning object files
clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	@rm -f $(NAME)
	@rm -rf $(DEST_DIR)/$(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild
re: fclean all

.PHONY: all clean fclean re

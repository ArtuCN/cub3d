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
FREE = free_all/free_cub.c
MATH = math/fmap.c
EVENTS = events/close.c events/some_mlx.c events/moves.c
WINDOW = window/my_pxl.c window/init_win.c window/minimap.c window/player_init.c window/init_cub.c
PARSING = parsing/init_data.c parsing/check_continue.c parsing/other_init.c parsing/parsing_map.c parsing/map_checks.c parsing/check_matrix.c
MAIN = main.c
RAYCASTING = raycasting/dda.c raycasting/raycasting.c raycasting/draw.c raycasting/raycasting2.c raycasting/raycasting3.c raycasting/draw2.c
GET_NEXT_LINE = includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c
LIBFT_DIR = includes/libft

# Libraries and include directories
LIBFT = $(LIBFT_DIR)/libft.a
MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = minilibx-linux
DEST_DIR = includes

# Compilation flags
FLAGS = -L$(DEST_DIR)/$(MLX_DIR) -lmlx -lX11 -lXext -lm -L$(LIBFT_DIR) -lft
COMPILE = gcc -Wall -Wextra -Werror -g

# Source and object files
SRCS = $(MAIN) $(WINDOW) $(PARSING) $(EVENTS) $(GET_NEXT_LINE) $(FREE) $(MATH) $(RAYCASTING)
OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Default target
all: $(DEST_DIR)/$(MLX_DIR) $(LIBFT) $(NAME)

# Cloning and setting up MinilibX
$(DEST_DIR)/$(MLX_DIR):
	@git clone $(MLX) $(DEST_DIR)/$(MLX_DIR)
	@cd $(DEST_DIR)/$(MLX_DIR) && ./configure

# Building libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Linking the final executable
$(NAME): $(OBJS) $(LIBFT)
	$(COMPILE) $(OBJS) $(FLAGS) -o $(NAME)

# Compiling object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPILE) -c $< -o $@

# Cleaning object files
clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	rm -f $(NAME)
	rm -rf $(DEST_DIR)/$(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild
re: fclean all

.PHONY: all clean fclean re

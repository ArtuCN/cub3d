# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconti <aconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 15:10:20 by aconti            #+#    #+#              #
#    Updated: 2024/07/31 13:17:18 by aconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

WINDOW = window/init_window.c
MAIN = main.c

SRCS := $(MAIN) $(WINDOW)
OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = minilibx-linux
DEST_DIR = includes
FLAGS = -L$(DEST_DIR)/$(MLX_DIR) -lmlx -lX11 -lXext
COMPILE = gcc -Wall -Wextra -Werror -g

all: $(DEST_DIR)/$(MLX_DIR) $(NAME)

$(DEST_DIR)/$(MLX_DIR):
    @git clone $(MLX) $(DEST_DIR)/$(MLX_DIR)
    @cd $(DEST_DIR)/$(MLX_DIR) && ./configure

$(NAME): $(OBJS)
    $(COMPILE) $(OBJS) $(FLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c
    @mkdir -p $(dir $@)
    $(COMPILE) -c $< -o $@

clean:
    rm -f $(OBJS)
    rm -rf $(OBJS_DIR)

fclean: clean
    rm -f $(NAME)
    rm -rf $(DEST_DIR)/$(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconti <aconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 17:07:03 by aconti            #+#    #+#              #
#    Updated: 2024/10/09 11:26:20 by aconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
MANDATORY_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
HEADER = libft.h
RED = '\033[0;91m'
NONE = '\033[0m'
all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	@ar rc ${NAME} ${MANDATORY_OBJS}
	@ranlib ${NAME}
bonus: ${BONUS_OBJS} ${MANDATORY_OBJS}
	@ar rc ${NAME} ${BONUS_OBJS} ${MANDATORY_OBJS}

%.o: %.c ${HEADER}
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f ${MANDATORY_OBJS} ${BONUS_OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus

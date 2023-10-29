# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:44:39 by dvan-den          #+#    #+#              #
#    Updated: 2023/10/26 20:55:56 by dvan-den         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f

SRC	=	ft_substr.c ft_strlen.c ft_strjoin.c ft_strtrim.c \
	     ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	     ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	     ft_split.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	     ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c \
	     ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	     ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	     ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	     ft_strdup.c ft_calloc.c ft_memcpy.c

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(LIB) $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
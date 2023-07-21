# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 11:32:54 by pgouasmi          #+#    #+#              #
#    Updated: 2023/07/20 10:53:44 by pgouasmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCSLIB = ./libft/ft_isalnum.c	\
		./libft/ft_isalpha.c		\
		./libft/ft_isascii.c		\
		./libft/ft_isdigit.c		\
		./libft/ft_isprint.c		\
		./libft/ft_itoa.c		\
		./libft/ft_strchr.c		\
		./libft/ft_strdup.c		\
		./libft/ft_strjoin.c		\
		./libft/ft_strlcat.c		\
		./libft/ft_strlcpy.c		\
		./libft/ft_strlen.c		\
		./libft/ft_strncmp.c		\
		./libft/ft_strnstr.c		\
		./libft/ft_strrchr.c		\
		./libft/ft_strtrim.c		\
		./libft/ft_substr.c		\
		./libft/ft_tolower.c		\
		./libft/ft_toupper.c		\
		./libft/ft_atoi.c		\
		./libft/ft_itoa.c		\
		./libft/ft_split.c 		\
		./libft/ft_strtrim.c		\
		./libft/ft_substr.c		\
		./libft/ft_bzero.c		\
		./libft/ft_memcpy.c		\
		./libft/ft_memmove.c		\
		./libft/ft_memset.c		\
		./libft/ft_strmapi.c		\
		./libft/ft_striteri.c	\
		./libft/ft_calloc.c		\
		./libft/ft_memcmp.c		\
		./libft/ft_memchr.c		\
		./libft/ft_putchar_fd.c	\
		./libft/ft_putstr_fd.c	\
		./libft/ft_putnbr_fd.c	\
		./libft/ft_putendl_fd.c	\
		./libft/ft_lstadd_front.c	\
		./libft/ft_lstlast.c		\
		./libft/ft_lstnew.c		\
		./libft/ft_lstsize.c		\
		./ft_printf/ft_printf.c		\
		./ft_printf/ft_putchar_pf.c	\
		./ft_printf/ft_putnbr_base.c	\
		./ft_printf/ft_putnbr_base_p.c\
		./ft_printf/ft_putstr_pf.c	\
		./get_next_line/get_next_line_utils.c	\
		./get_next_line/get_next_line.c	\

OBJS = ${SRCSLIB:.c=.o}
HEADER = libft.h
CC = cc
FLAG = -Wall -Wextra -Werror -ggdb3

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER) Makefile
			ar -rcs $(NAME) $(OBJS)

%.o:	%.c $(HEADER) Makefile
			$(CC) $(FLAG) -I . -c $< -o $@

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)
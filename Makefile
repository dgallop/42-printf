# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:05:14 by dgallo-p          #+#    #+#              #
#    Updated: 2021/12/09 15:10:01 by dgallo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

SRCS        = ft_printf.c ft_printf_libft.c ft_write_nb.c ft_write.c ft_write_hexa.c

OBJS        = $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
				$(AR) $(NAME) $(OBJS)
				@echo "$(NAME) created"
				@ranlib $(NAME)
				@echo "$(NAME) inexed"

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
				@echo "deleted"

fclean: clean
				$(RM) $(NAME)
				@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
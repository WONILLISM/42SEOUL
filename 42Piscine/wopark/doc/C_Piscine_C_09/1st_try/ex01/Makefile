# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 15:40:17 by wopark            #+#    #+#              #
#    Updated: 2020/08/21 15:41:57 by wopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = cr
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDES_DIR = ./includes
INCLUDES = ft.h

SRCS_DIR = ./srcs
SRCS = ft_putchar.c \
	   ft_swap.c \
	   ft_putstr.c \
	   ft_strlen.c \
	   ft_strcmp.c
OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

re : fclean all

$(NAME) : $(addprefix $(INCLUDES_DIR)/, $(INCLUDES)) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.c.o :
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $(<:.c=.o)

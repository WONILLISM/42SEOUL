# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonilpark <wonilpark@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 19:32:52 by wonilpark         #+#    #+#              #
#    Updated: 2021/08/06 19:32:56 by wonilpark        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# output
NAME =		philosophers

AR =		ar rcs
RM =		rm -f

# compile option
CC =		gcc
# CFLAGS =	-Wall -Wextra -Werror -fsanitize=address -g
CFLAGS =	-Wall -Wextra -Werror

# source files
MAIN_DIR =	./
MAIN_SRCS = \
			main.c \
			init.c \
			philo_utils.c \
			philosophers.c

UTILS_DIR =	./utils/
UTILS_SRCS = \
			ft_atoi.c \
			ft_isdigit.c

MANDATORY =	\
			$(addprefix $(MAIN_DIR), $(MAIN_SRCS)) \
			$(addprefix $(UTILS_DIR), $(UTILS_SRCS))

OBJS =	$(MANDATORY:.c=.o)

# roles
all :	$(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re

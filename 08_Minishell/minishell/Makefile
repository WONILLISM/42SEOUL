# output
NAME =		minishell

AR =		ar rcs
RM =		rm -f

# compile option
CC =		gcc
# CFLAGS =	-Wall -Wextra -Werror -fsanitize=address -g
CFLAGS =	-Wall -Wextra -Werror

# library
LIBFT_DIR =	./includes/libft/
LIBFT =	libft.a

# source files
MAIN_DIR =	./
MAIN_SRCS = \
			main.c

WOPARK_DIR =	./wopark/
WOPARK_SRCS = \
			parse.c \
			parse_init.c \
			parse_utils.c \
			parse_env.c \
			parse_free.c \
			parse_error.c \
			signal.c \
			linkedlist.c \
			cursor.c \
			redirection.c \
			history.c \
			terminal_handle.c \
			terminal_utils.c

JUNGHWKI_DIR =	./junghwki/
JUNGHWKI_SRCS = \
			envv_lst.c \
			execute_builtin.c \
			execute_builtin_utils.c \
			ft_cd.c \
			ft_echo.c \
			ft_export.c \
			ft_export_utils.c \
			ft_pwd.c \
			ft_unset.c \
			ft_execve.c \
			utils.c \
			ft_exit.c \
			ft_error.c

MANDATORY =	\
			$(addprefix $(MAIN_DIR), $(MAIN_SRCS)) \
			$(addprefix $(WOPARK_DIR), $(WOPARK_SRCS)) \
			$(addprefix $(JUNGHWKI_DIR), $(JUNGHWKI_SRCS))

OBJS =	$(MANDATORY:.c=.o)

# roles
all :	$(NAME)

# library :	$(LIBFT)

$(NAME) :	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $< -o $(NAME) $(LIBFT) $(OBJS) -lncurses

$(LIBFT) :
			make -C $(LIBFT_DIR)
			make bonus -C $(LIBFT_DIR)
			mv $(LIBFT_DIR)$(LIBFT) .

clean :
			$(RM) $(OBJS) $(LIBFT)
			make clean -C $(LIBFT_DIR)

fclean : clean
			$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re

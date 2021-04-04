# output
NAME = cub3D

# compile option
CC = gcc
FLAG = -Wall -Wextra -Werror

# library
LIBFT_DIR = ./includes/libft/
LIBFT = libft.a

GNL_DIR = ./includes/libft/GNL
GNL = gnl.a

OPENGL_DIR = ./mlx/
OPENGL = mlx.a

# source files
SRCS_DIR = ./srcs/
MAIN_NAME = \
		main.c

PARSE_DIR = $(SRCS_DIR)parse/
PARSE_NAME = \
		init_parse.c \
		parse_gamedata_1.c \
		parse_gamedata_2.c \
		parse_util.c \
		valid_map.c

SCREEN_DIR = ${SRCS_DIR}screen/
SCREEN_NAME = \
		screen.c \
		vec.c

MANDATORY = \
		$(addprefix $(SRCS_DIR), $(MAIN_NAME)) \
		$(addprefix $(PARSE_DIR), $(PARSE_NAME)) \
		$(addprefix $(SCREEN_DIR), $(SCREEN_NAME))

OBJS = $(MANDATORY:.c=.o)

HEADERS = \
		





SRCS		= ./ft_printf.c \
			  ./printf_parser.c \
			  ./proc_container.c \
			  ./proc_sign.c \
			  ./proc_int.c \
			  ./proc_char.c \
			  ./proc_string.c \
			  ./proc_unsigned_int.c \
			  ./proc_hex.c \
			  ./proc_pointer.c \
			  ./proc_percent.c \
			  ./proc_n.c


OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o

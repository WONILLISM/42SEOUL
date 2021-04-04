# output
NAME = cub3D

# compile option
CC = gcc
FLAG = -Wall -Wextra -Werror
AR = ar rcs		
RM = rm -f		

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

# rules
all : $(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(FLAG) -o $(NAME) $(OBJS) \
			-L ./includes/opengl/ -lmlx -framework OpenGL -framework Appkit

lib : library

library : $(LIBFT) $(OPENGL)

$(LIBFT) :
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

$(OPENGL) :
	make -C $(OPENGL_DIR)
	mv $(OPENGL_DIR)$(OPENGL) ./$(OPENGL)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

.PHONY:	all clean fclean re
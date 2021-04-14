# output
NAME = cub3D

# compile option
CC = gcc
AR = ar rcs
RM = rm -f

# library
LIBFT_DIR = ./includes/libft/
LIBFT = libft.a

GNL_DIR = ./includes/libft/GNL/
GNL = gnl.a

OPENGL_DIR = ./includes/opengl/
OPENGL = libmlx.a

MMS_DIR = ./includes/mms/
MMS = libmlx.dylib

SCREEN_SHOT = ./cub3D_screenshot.bmp

# source files
SRCS_DIR = ./srcs/
MAIN_NAME = \
		main.c \
		save_bitmap.c

PARSE_DIR = $(SRCS_DIR)parse/
PARSE_NAME = \
		init_parse.c \
		parse_gamedata_1.c \
		parse_gamedata_2.c \
		parse_util.c \
		valid_map.c

SCREEN_DIR = ${SRCS_DIR}screen/
SCREEN_NAME = \
		init.c \
		key_manage.c \
		ray_cast.c \
		screen.c \
		vec.c \
		sprite.c \
		sprite_util.c

MANDATORY = \
		$(addprefix $(SRCS_DIR), $(MAIN_NAME)) \
		$(addprefix $(PARSE_DIR), $(PARSE_NAME)) \
		$(addprefix $(SCREEN_DIR), $(SCREEN_NAME))

OBJS = $(MANDATORY:.c=.o)

# rules
all : $(NAME)

library : $(LIBFT) $(OPENGL) $(MMS) $(GNL)

$(NAME) :	library $(OBJS)
			$(CC) -Werror -Wextra -Wall -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(OPENGL) $(MMS)\
			-framework OpenGL -framework Appkit -fsanitize=address

$(LIBFT) :
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

$(GNL) :
	make -C $(GNL_DIR)
	mv $(GNL_DIR)$(GNL) .

$(OPENGL) :
	make -C $(OPENGL_DIR)
	mv $(OPENGL_DIR)$(OPENGL) ./$(OPENGL)

$(MMS) :
	make -C $(MMS_DIR)
	mv $(MMS_DIR)$(MMS) ./$(MMS)

clean:
	$(RM) $(OBJS) $(LIBFT) $(GNL) $(OPENGL) $(MMS) $(SRCS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(OPENGL_DIR)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(SCREEN_SHOT)

re : fclean $(NAME)

.PHONY:	all clean fclean re

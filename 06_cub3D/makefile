# output
NAME = cub3D

# compile option
CC = gcc
FLAG = -Wall -Wextra -Werror -03

# Library
LIBFT_DIR = ./includes/Libft
LIBFT = libft.a

GNL_DIR = ./includes/GNL
GNL = gnl.a

OPENGL_DIR = ./includes/opengl
OPENGL = opengl.a

# source files
SRCS_DIR = ./srcs/
SRCS =	main.c \
		cub3d.c \
		vec.c 

MANDATORY = $(addprefix $(SRCS_DIR), %(SRCS))

OBJS = $(MANDATORY:.c=.o)

HEADERS = \
			./includes/cub3d.h \
			./includes/key.h 
		
# rules
all : $(NAME)

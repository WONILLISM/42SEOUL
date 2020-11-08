C = clang

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

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

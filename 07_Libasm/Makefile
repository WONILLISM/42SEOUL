# output
NAME	=	libasm.a

# compile option
CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra
AR	=	ar rcs

RM	=	rm -f

# source files
SRCS	=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s

# object files
OBJS	=	$(SRCS:.s=.o)

# assemble
NASM	=	nasm
NFLAGS = -f macho64

# test
TEST	=	test

# rules
%.o		:	%.s
			$(NASM) $(NFLAGS) $<


all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME) $(TEST)

re		:	fclean all

:.PHONY	:	clean fclean test

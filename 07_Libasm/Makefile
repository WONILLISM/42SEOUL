NAME	=	libasm.a

SRCS	=	ft_strlen.s

OBJS	=	$(SRCS:.s=.o)

NASM	=	nasm
NASM_FLAGS = -f macho64

FLAGS	=	-Wall -Werror -Wextra

%.o		:	%.s
			$(NASM) $(NASM_FLAGS) $<


all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:	rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean $(NAME)
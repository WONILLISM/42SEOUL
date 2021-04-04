NAME = libft.a	# 아카이브 파일 이름

CC = gcc	# CC : C Compiler
CFLAGS = -Wall -Wextra -Werror	# C 컴파일러 플래그
AR = ar rcs		# AR :아카이브 관리 프로그램 // AR 옵션 rcs
RM = rm -f		# 쉘 명령어

FILES = ft_strlen \
		ft_strlcpy \
		ft_strchr \
		ft_strdup \
		ft_strncmp \
		ft_atoi \
		ft_isdigit \
		ft_split \
		ft_lstnew \
	  	ft_lstadd_front \
	  	ft_lstsize \
	  	ft_lstlast \
	  	ft_lstadd_back \
	  	ft_lstdelone \
	  	ft_lstclear \
	  	ft_lstiter \
	  	ft_lstmap 

SRCS_DIR = ./
SRCS = \
		$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES))) # SRCS_DIR에 있는 확장자가 c이고 파일명이 FILES인 파일

OBJS_DIR = ./
OBJS = \
		$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))	# OBJS_DIR에 있는 확장자가 o이고 파일명이 FILES인 파일

# make 명령어
.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re

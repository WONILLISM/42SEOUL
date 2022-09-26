# output
NAME = ex06

# compiler
CPP	= clang++

# cpp flags
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

AR = ar rcs
RM = rm -f

# source files
SRCS_DIR = ./
SRCS = \
		main.cpp \
		Karen.cpp

EX06 = $(addprefix $(SRCS_DIR), $(SRCS))

# object files
OBJS = $(EX06:.cpp=.o)

# roles
all : $(NAME)

$(NAME) : $(OBJS)
		$(CPP) $(CPPFLAGS) $^ -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

#test : $(NAME)

.PHONY : all clean fclean re test

# output
NAME = ex01

# compiler
CXX	= clang++

# cpp flags
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

AR = ar rcs
RM = rm -f

# source files
SRCS_DIR = ./
SRCS = \
		Bureaucrat.cpp \
		Form.cpp \
		main.cpp \

EX01 = $(addprefix $(SRCS_DIR), $(SRCS))

# object files
OBJS = $(EX01:.cpp=.o)

# roles
all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CPPFLAGS) $^ -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

#test : $(NAME)

.PHONY : all clean fclean re test

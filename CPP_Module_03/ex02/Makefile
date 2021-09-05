# output
NAME = ex02

# compiler
CXX	= clang++

# cpp flags
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

AR = ar rcs
RM = rm -f

# source files
SRCS_DIR = ./
SRCS = \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		main.cpp \

EX02 = $(addprefix $(SRCS_DIR), $(SRCS))

# object files
OBJS = $(EX02:.cpp=.o)

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

# output
NAME = ex00

# compiler
CXX	= clang++

# cpp flags
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

AR = ar rcs
RM = rm -f

# source files
SRCS_DIR = ./
SRCS = \
		ClapTrap.cpp \
		main.cpp \

EX00 = $(addprefix $(SRCS_DIR), $(SRCS))

# object files
OBJS = $(EX00:.cpp=.o)

# roles
all : $(NAME)

$(NAME) : $(OBJS)
		@$(CXX) $(CXXFLAGS) $^ -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

#test : $(NAME)

.PHONY : all clean fclean re test

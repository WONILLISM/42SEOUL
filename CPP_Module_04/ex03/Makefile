# output
NAME = ex03

# compiler
CXX	= clang++

# cpp flags
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

AR = ar rcs
RM = rm -f

# source files
SRCS_DIR = ./
SRCS = \
		main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp \

EX03 = $(addprefix $(SRCS_DIR), $(SRCS))

# object files
OBJS = $(EX03:.cpp=.o)

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

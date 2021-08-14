# output
NAME = megaphone

# compiler
CPP	= clang++

# cpp flags
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

AR = ar rcs
RM = rm -f

# source files
SRCS_DIR = ./
SRCS = megaphone.cpp

EX00 = $(addprefix $(SRCS_DIR), $(SRCS))

# object files
OBJS = $(EX00:.cpp=.o)

# roles
all : $(NAME)

$(NAME) : $(OBJS)
		$(CPP) $(CPPFLAGS) $^ -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

test : $(NAME)
		./megaphone "shhhhh... I think the students are asleep..."
		./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
		./megaphone

.PHONY : all clean fclean re test

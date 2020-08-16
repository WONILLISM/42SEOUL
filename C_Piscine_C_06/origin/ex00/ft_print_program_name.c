#include <unistd.h>

void ft_print_program_name(char *str)
{
    while(*str)
        write(1, str++, 1);
}
int main(int argc, char **argv)
{
    if (argc)
        ft_print_program_name(argv[0]);
    write(1, "\n", 1);
    return (0);
}
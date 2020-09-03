#include <unistd.h>

int ft_is_space(char c)
{
    return ((c >= 9 && c <= 13) || c == ' ');
}
int main(int argc, char **argv)
{
    int len;

    len = 0;
    if (argc == 2)
    {
        while (argv[1][len])
            len++;
        len--;
        while (ft_is_space(argv[1][len]))
            len--;
        while(!ft_is_space(argv[1][len]))
            len--;
        while(argv[1][++len] && !ft_is_space(argv[1][len]))
            write(1, &argv[1][len], 1);
    }
    write(1, "\n", 1);
    return (0);
}
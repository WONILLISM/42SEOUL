#include <unistd.h>

int is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int is_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}

void alpha_mirror(char *str)
{
    while (*str)
    {
        if (is_lower(*str))
            *str = -(*str - 'a' - 25) + 'a';
        else if (is_upper(*str))
            *str = -(*str - 'A' - 25) + 'A';
        write(1, str++, 1);
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        alpha_mirror(argv[1]);
    write(1, "\n", 1);

    return 0;
}
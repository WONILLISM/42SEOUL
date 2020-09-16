#include <unistd.h>

int     main(int argc, char **argv)
{
    char *str;

    if (argc == 2)
    {
        str = argv[1];
        while ((*str >= 9 && *str <= 13) || *str == ' ')
            str++;
        while (*str)
        {
            if (*str == ' ')
            {
                while ((*str >= 9 && *str <= 13) || *str == ' ')
                    str++;
                if (*str)
                    write(1, "   ", 3);
            }
            else write(1, str++, 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
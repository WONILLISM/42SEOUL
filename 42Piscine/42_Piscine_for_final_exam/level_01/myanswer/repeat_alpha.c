#include <unistd.h>

int ft_is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return -1;
    else
        return 0;
}
int main(int argc, char **argv)
{
    int i;
    int j;
    char cur;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            cur = argv[1][i];
            if (ft_is_alpha(cur) == 1)
                j = cur - 'a' + 1;
            else if (ft_is_alpha(cur) == -1)
                j = cur - 'A' + 1;
            else
            {
                write(1, &cur, 1);
                i++;
                continue ;
            }  
            while (j--)
                write(1, &cur, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
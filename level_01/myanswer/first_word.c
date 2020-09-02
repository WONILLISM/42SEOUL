#include <unistd.h>

int is_space(char c)
{
    return ((c >= 9 && c <= 13) || c == ' ');
}
int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc  == 2)
    {
        while (is_space(argv[1][i]))
            i++;
        while (!is_space(argv[1][i]) && argv[1][i])
            write(1, &argv[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}
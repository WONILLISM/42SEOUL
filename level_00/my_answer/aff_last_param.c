#include <unistd.h>

int main(int argc, char **argv)
{
    char *str;
    if (argc >= 2){
        str = argv[argc - 1];
        while (*str)
            write(1, str++, 1);
    }
    write(1, "\n", 1);
    return (0);
}
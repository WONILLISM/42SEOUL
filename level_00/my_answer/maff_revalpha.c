#include <unistd.h>

int main(void)
{
    int i;
    char c;

    i = 0;
    while (i < 26)
    {
        c = i % 2 == 0? ('z' - i) : ('Z' - i);
        write(1, &c, 1);
        i++;
    }
    return (0);
}
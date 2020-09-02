#include <unistd.h>

int main(void)
{
    int i;
    char c;

    i = 0;
    while (i < 26)
    {
        c = i % 2 == 0? ('a' + i) : ('A' + i);
        write(1, &c, 1);
        i++;
    }
    return (0);
}
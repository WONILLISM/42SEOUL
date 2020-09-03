#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int print_res(int a, int b, char *op)
{
    int res;
    char oper = op[0];
    if (oper == '+')
        res = a + b;
    else if (oper == '-')
        res = a - b;
    else if (oper == '*')
        res = a * b;
    else if (oper == '/')
        res = a / b;
    else if (oper == '%')
        res = a % b;
    return res;
}
void do_op(char **argv)
{
    int i;
    int a;
    int b;
    char *oper;

    i = 1;
    while (argv[i])
    {
        if (i == 1)
            a = atoi(argv[i]);
        else if (i == 2)
            oper = argv[i];
        else if (i == 3)
            b = atoi(argv[i]);
        i++;
    }
    printf("%d", print_res(a, b, oper));
}

int main(int argc, char **argv)
{
    if (argc == 4)
        do_op(argv);
    write(1, "\n", 1);
    return 0;
}

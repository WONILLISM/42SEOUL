
#include <stdio.h>

void func(char *str)
{
    int i=0;
    unsigned char cur;
    while(str[i]){
        cur = str[i++];
        printf("%c ", cur);
        printf("%d\n", cur);
    }
}
int main()
{
    char str[2] = {-1, -2};
    func(str);
    return 0;
}
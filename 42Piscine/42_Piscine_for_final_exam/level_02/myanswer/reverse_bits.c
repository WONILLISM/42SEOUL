#include <stdio.h>

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char   ret;
	int             i;
	
	i = 1;
	ret = 0;
	while (i < 256)
	{
		ret = ret *2 + ((octet & i) == i);
		i <<= 1;
	}
	return ret;
}

int main(){
    printf("%d", reverse_bits(65));
    return 0;
}
// 0100 0001  65
// 1000 0010  130
// ret = 0
// i = 1 : ret = 0 * 2 + 0 => 0
// i = 2 : ret = 0 * 2 + 1 => 1
// i = 4 : ret = 1 * 2 + 1 => 3
// i = 8 : ret = 3 * 2 + 1 => 7
// i = 16 : ret = 7 * 2 + 1 => 15
// i = 32 : ret = 15 * 2 + 1 => 31
// i = 64 : ret = 31 * 2 + 1 => 63
// i = 128 : ret = 63 * 2 + 1 => 127



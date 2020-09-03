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
    printf("%d", reverse_bits(254));
    return 0;
}
// 1111 1110  254
// 0111 1111  127

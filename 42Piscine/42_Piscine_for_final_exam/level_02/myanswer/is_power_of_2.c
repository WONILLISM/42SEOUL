int	    is_power_of_2(unsigned int n)
{
	return ((n & (-n)) == n);
}

// 8 = 1000
// 1의 보수 0111
// 2의 보수 = 1의 보수 + 1 : 컴퓨터의 음수 표현
// int 크기 = 4byte
// int 범위 = -2147483648 ~ 2147483647
//          = - 2^32  ~ 2^32 -1

//   1000
//   0111
// +    1
// 8 = 0000 0000 0000 0000 0000 0000 0000 1000
// 1의 보수  = 1111 1111 1111 1111 1111 1111 1111 0111
//                                                 +1
// 2의 보수 = 1111 1111 1111 1111 1111 1111 1111 1000
//    8 = 0000 0000 0000 0000 0000 0000 0000 1000
//   -8 = 1111 1111 1111 1111 1111 1111 1111 1000
// &      0000 0000 0000 0000 0000 0000 0000 1000
//
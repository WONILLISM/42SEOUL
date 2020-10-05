#include "libft.h"

int	ft_isalpha(int c)
{
	return (((char)c >= 'a' && (char)c <= 'z')
	|| ((char)c >= 'A' && (char)c <= 'Z'));
}

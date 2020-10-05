#include "libft.h"

int	ft_tolower(int c)
{
	if ((char)c >= 'A' && (char)c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

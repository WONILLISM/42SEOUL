#include "libft.h"

int	ft_isprint(int c)
{
	return (!((char)c < ' ' || (char)c == 127));
}

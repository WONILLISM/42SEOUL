#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct	s_info
{
	int		byte;
	int		minus;
	int		width;
	int		precision;
	int		zero;
	int		plus;
	int		space;
	int		hex;
	int		len;
}				t_info;

int	ft_printf(const char *, ...);
#endif

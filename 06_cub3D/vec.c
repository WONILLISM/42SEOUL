#include "cub3d.h"
// #include <stdio.h>
// #include <math.h>

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

t_vec	new_vector(double x, double y)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_vec	add_vector(t_vec a, t_vec b)
{
	t_vec	ret;
	
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_vec	sub_vector(t_vec a, t_vec b)
{
	t_vec	ret;
	
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	return (ret);
}

double	cal_vector_len(t_vec a, t_vec b)
{
	return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));
}

void	draw_line(t_vec a, t_vec b)
{
	double	len;

	len = cal_vector_len(a, b);

}
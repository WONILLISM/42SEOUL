#include "cub3d.h"

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

t_vec	mul_vector(t_vec v, double k)
{
	t_vec	ret;
	
	ret.x = v.x * k;
	ret.y = v.y * k;
	return (ret);
}

t_vec	rotate_vec(t_vec v, double angle)
{
	t_vec	ret;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	ret.x = cos_angle * v.x - sin_angle * v.y;
	ret.y = sin_angle * v.x + sin_angle * v.y;
	return (ret);
}

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

t_vec	rot_vector(t_vec v, double rs)
{
	t_vec	ret;

	ret.x = v.x * cos(rs * DEG2RAD) - v.y * sin(rs * DEG2RAD);
	ret.y = v.x * sin(rs * DEG2RAD) + v.y * cos(rs * DEG2RAD);
	return (ret);
}

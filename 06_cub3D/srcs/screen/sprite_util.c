#include "../../includes/cub3d.h"

void	init_sprite(t_screen *s)
{
	int		i;
	int		j;
	int		idx;

	idx = 0;
	i = -1;
	while (++i < s->row_size)
	{
		j = -1;
		while (++j < s->col_size)
		{
			if (s->map_arr[i][j] == '2')
			{
				s->sprite[idx].y = (double)i + 0.5;
				s->sprite[idx].x = (double)j + 0.5;
				idx++;
			}
		}
	}
}

void	sort_sprite(t_screen *s)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < s->numofsprt)
	{
		j = i;
		while (j < s->numofsprt)
		{
			if (s->sprite[i].dist < s->sprite[j].dist)
			{
				tmp = s->sprite[j];
				s->sprite[j] = s->sprite[i];
				s->sprite[i] = tmp;
			}
			j++;
		}
		i++;
	}
}
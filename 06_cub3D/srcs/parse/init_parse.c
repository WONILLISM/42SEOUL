#include "../../includes/cub3d.h"

void	init_bfs(t_gamedata *d, t_bfs *a)
{
	int		i;

	a->f = 0;
	a->r = 0;
	a->dx[0] = 1;
	a->dx[1] = 0;
	a->dx[2] = -1;
	a->dx[3] = 0;
	a->dy[0] = 0;
	a->dy[1] = 1;
	a->dy[2] = 0;
	a->dy[3] = -1;
	a->col = d->scrn.col_size;
	a->row = d->scrn.row_size;
	a->is_empty_player = 0;
	if (find_arguments(d, a) != 1)
		error_message("empty or many player", d);
	a->chk = (int *)malloc(sizeof(int) * a->row * a->col);
	i = -1;
	while (++i < a->row * a->col)
		a->chk[i] = 0;
}

void	init_player(t_gamedata *d, t_bfs *a, int k)
{
	d->scrn.p.pos.x = a->cur.x + 0.5;
	d->scrn.p.pos.y = a->cur.y + 0.5;
	d->scrn.p.dir.x = a->dx[k];
	d->scrn.p.dir.y = a->dy[k];
	d->scrn.plane.x = a->dx[(int)(k + 1) % 4] * 0.66;
	d->scrn.plane.y = a->dy[(int)(k + 1) % 4] * 0.66;
	d->scrn.p.move_speed = 0.05f;
	d->scrn.p.rot_speed = 0.02f;

	// printf("%f\n",d->scrn.p.pos.x);
	// printf("%f\n",d->scrn.p.pos.y);
	// printf("%f\n",d->scrn.p.dir.x);
	// printf("%f\n",d->scrn.p.dir.y);
	// printf("%f\n",d->scrn.plane.x);
	// printf("%f\n",d->scrn.plane.y);
}

void	init_gamedata(t_gamedata *d)
{
	int		i;
	
	i = -1;
	while (++i < 8)
		d->chk_parse[i] = 0;
	d->scrn.sprite = 0;
	d->scrn.ZBuffer = 0;
	d->scrn.numofsprt = 0;
	d->scrn.height = 0;
	d->scrn.width = 0;
	d->ceil_color = -1;
	d->floor_color = -1;
	d->north_img = 0;
	d->south_img = 0;
	d->east_img = 0;
	d->west_img = 0;
	d->sprite_img = 0;
	d->scrn.map_arr = 0;
}

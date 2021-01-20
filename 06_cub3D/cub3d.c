#include "cub3d.h"

void	init_window(t_archive *a)
{
	a->width = 700;
	a->height = 700;
	a->m.mlx = mlx_init();
	a->m.win = mlx_new_window(a->m.mlx, a->width, a->height, "cub3d");
}

void	init_keys(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->q = 0;
	key->e = 0;
}
void	init_player(t_player *p)
{
	p->x = 250;
	p->y = 250;
	p->dir = 0;
}

int		key_pressed(int key, t_key *key_info)
{
	if (key == KEY_W)
		key_info->w = 1;
	else if (key == KEY_S)
		key_info->s = 1;
	else if (key == KEY_A)
		key_info->a = 1;
	else if (key == KEY_D)
		key_info->d = 1;
	else if (key == KEY_Q)
		key_info->q = 1;
	else if (key == KEY_E)
		key_info->e = 1;
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}

int		key_released(int key, t_key *key_info)
{
	if (key == KEY_W)
		key_info->w = 0;
	else if (key == KEY_S)
		key_info->s = 0;
	else if (key == KEY_A)
		key_info->a = 0;
	else if (key == KEY_D)
		key_info->d = 0;
	else if (key == KEY_Q)
		key_info->q = 0;
	else if (key == KEY_E)
		key_info->e = 0;
	return (0);
}

void	move_player(t_archive *a)
{
	if (a->key.w)
		a->p.y -= 5;
	else if (a->key.s)
		a->p.y += 5;
	else if (a->key.a)
		a->p.x -= 5;
	else if (a->key.d)
		a->p.x += 5;
}

int		main_loop(t_archive *a)
{
	mlx_clear_window(a->m.mlx, a->m.win);
	mlx_pixel_put(a->m.mlx, a->m.win, a->p.x, a->p.y, 0xffff00);
	move_player(a);
	return (0);
}

int	 main(void)
{
	t_archive	archive;

	init_window(&archive);
	init_player(&archive.p);

	mlx_hook(archive.m.win, 2, 1, key_pressed, &(archive.key));
	mlx_hook(archive.m.win, 3, 2, key_released, &(archive.key));
	mlx_loop_hook(archive.m.mlx, main_loop, &archive);
	mlx_loop(archive.m.mlx);
	return (0);
}
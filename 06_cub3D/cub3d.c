#include "cub3d.h"

void	init_window(t_archive *a)
{
	a->width = 700;
	a->height = 700;
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, a->width, a->height, "cub3d");
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
	if (a->key->w)
		a->p->y -= 5;
	else if (a->key->s)
		a->p->y += 5;
	else if (a->key->a)
		a->p->x -= 5;
	else if (a->key->d)
		a->p->x += 5;
}

int		main_loop(t_archive *a)
{
	mlx_clear_window(a->mlx, a->win);
	mlx_pixel_put(a->mlx, a->win, a->p->x, a->p->y, 0xffff00);
	return (0);
}

int	 main(void)
{
	t_archive	archive;
	t_player	player;
	t_key		key;

	archive.p = &player;
	archive.key = &key;
	init_window(&archive);
	init_player(&player);

	mlx_loop_hook(archive.mlx, main_loop, &archive);
	mlx_hook(archive.win, 2, 1, key_pressed, &(archive.key));
	mlx_hook(archive.win, 3, 2, key_released, &(archive.key));
	mlx_loop(archive.mlx);
	return (0);
}
#include "cub3D.h"

int		g_map[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,0,1,0,0,1,1,1,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};

int		draw_map_2D(t_archive *arcv)
{
	int		i;
	int		j;
	int		wall_w;
	int		wall_h;

	i = 0;
	wall_w = ((arcv->screen->w) / 2) / 10;
	wall_h = (arcv->screen->h) / 10;
	arcv->wall_img = create_square(arcv, wall_w, wall_h, 0xffffff);
	while (i <= 10)
	{
		j = 0;
		while (j <= 10)
		{
			if (i < 10 && j < 10 && g_map[i][j] == 1)
				mlx_put_image_to_window(arcv->screen->mlx, arcv->screen->win, arcv->wall_img->ptr, j*wall_w, i*wall_h);
			j++;
		}
		i++;
	}
	return (0);
}
int		player_init(t_archive *arcv)
{
	arcv->p->px = 300.0f;
	arcv->p->py = 300.0f;
	if (!(arcv->player_img = create_square(arcv, 5, 5, 0xffff00)))
		return (-1);
	return (0);
}

int		archive_init(t_archive *arcv)
{
	arcv->screen->mlx = mlx_init();
	arcv->screen->w = 1600;
	arcv->screen->h = 800;
	if (player_init(arcv) == -1)
		return (-1);
	arcv->screen->win= mlx_new_window(arcv->screen->mlx, arcv->screen->w, arcv->screen->h, "cub3D");
	return (0);
}

int		main_loop(t_archive *arcv)
{
	mlx_clear_window(arcv->screen->mlx, arcv->screen->win);
	draw_map_2D(arcv);
	mlx_put_image_to_window(arcv->screen->mlx, arcv->screen->win, arcv->player_img->ptr, arcv->p->px, arcv->p->py);
	return (0);
}

void	player_move(t_archive *arcv, int key)
{
	int	dx;
	int	dy;
	if (key == _W)
		arcv->p->py -= 5;
	else if (key == _S)
		arcv->p->py += 5;
	else if (key == _A)
		arcv->p->px -= 5;
	else if (key == _D)
		arcv->p->px += 5;
}

int		key_pressed(int key, t_archive *arcv)
{
	if (key == _W || key == _A || key == _S || key == _D)
		player_move(arcv, key);
	else if (key == _ESC)
		exit(0);
	return (0);
}

int		main(void)
{
	t_archive	archive;
	t_screen	screen;
	t_player	player;

	archive.screen = &screen;
	archive.p = &player;
	if (archive_init(&archive) == -1)
		return (0);
	mlx_loop_hook(archive.screen->mlx, &main_loop, &archive);
	mlx_hook(archive.screen->win, 2, 0, key_pressed, &archive);
	mlx_loop(archive.screen->mlx);
	free(archive.player_img);
	free(archive.wall_img);
	return (0);
}

#include "../includes/cub3d.h"

int		main(void)
{
	t_gamedata	gamedata;
	t_screen	*s;

	s = &gamedata.scrn;
	s->mlx = mlx_init();
	init_gamedata(&gamedata);
	parse_gamedata(&gamedata, "cub3d_2.cub");
	s->win = mlx_new_window(gamedata.scrn.mlx, gamedata.scrn.width, gamedata.scrn.height, "cub3d");	
	is_valid_map(&gamedata);
	cub3d(&gamedata);
	free_gamedata(&gamedata);
	return (0);
}
#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_gamedata	gamedata;
	t_screen	*s;

	s = &gamedata.scrn;
	s->mlx = mlx_init();
	init_gamedata(&gamedata);
	parse_gamedata(&gamedata, argv[1]);
	s->win = mlx_new_window(gamedata.scrn.mlx, gamedata.scrn.width, gamedata.scrn.height, "cub3d");	
	is_valid_map(&gamedata);
	cub3d(&gamedata);
	free_gamedata(&gamedata);
	return (0);
}
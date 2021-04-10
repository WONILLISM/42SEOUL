#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_gamedata	gamedata;
	t_screen	*s;

	if (argc >= 2 && argc <= 3)
	{
		if (argc == 3)
			chk_save_cmd(argv, &gamedata);
		gamedata.argc = argc;
		s = &gamedata.scrn;
		s->mlx = mlx_init();
		init_gamedata(&gamedata);
		parse_gamedata(&gamedata, argv[1]);
		s->win = mlx_new_window(gamedata.scrn.mlx, gamedata.scrn.width, gamedata.scrn.height, "cub3d");
		// printf("%d\n", is_valid_map(&gamedata));
		if (is_valid_map(&gamedata))
			error_message("map", &gamedata);
		cub3d(&gamedata);
		free_gamedata(&gamedata);
	}
	return (0);
}

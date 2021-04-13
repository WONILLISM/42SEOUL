/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:35:24 by wopark            #+#    #+#             */
/*   Updated: 2021/04/13 14:36:19 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_exit(void)
{
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_gamedata	gamedata;
	t_screen	*s;

	if (argc >= 2 && argc <= 3)
	{
		gamedata.argc = argc;
		s = &gamedata.scrn;
		s->mlx = mlx_init();
		init_gamedata(&gamedata);
		parse_gamedata(&gamedata, argv[1]);
		if (argc == 3)
			chk_save_cmd(argv, &gamedata);
		s->win = mlx_new_window(gamedata.scrn.mlx, gamedata.scrn.width,
		gamedata.scrn.height, "cub3d");
		if (is_valid_map(&gamedata))
			error_message("map", &gamedata);
		cub3d(&gamedata);
		free_gamedata(&gamedata);
	}
	else
		printf("argument error\n");
	return (0);
}

#include <stdio.h>
#include "includes/opengl/mlx.h"

typedef struct	s_window 
{
	void	*mlx;
	void	*win;

	int		width;
	int		height;

	int		row;
	int		col;
	int		grid_color;
}				t_window;

int     main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "cub3d");
	mlx_loop(mlx);
	return (0);
}
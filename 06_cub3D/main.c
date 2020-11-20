#include "cub3D.h"

int		move_player(key)
{
	return (0);
}
int		terminate_window(void)
{
	write(1, "window is terminated.\n", 23);
	exit(0);
	return (0);
}

int		key_parsing(int key, void *param)
{
	if (key == 53 && param)
		return (terminate_window());
	else if ((key >= 123 && key <= 126) && param)
		return (move_player(key));
	else
		return (-1);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_pixel_put(mlx_ptr, win_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, 0x00ff0000);
	mlx_key_hook(win_ptr, key_parsing, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}

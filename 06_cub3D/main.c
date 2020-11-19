#include <stdlib.h>
#include <unistd.h>
#include "./opengl/mlx.h"

int
int		terminate_window(int key, void *param)
{
	if (key == 53 && param)
	{
		write(1, "window is terminated.\n", 23);
		exit(0);
	}
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x00ff0000);
	mlx_key_hook(win_ptr, terminate_window, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}

#ifndef _CUB3D_H_
# define _CUB3D_H_
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <stdlib.h>
# include <unistd.h>
# include "./opengl/mlx.h"

typedef struct	s_window
{
	void	*mlx;
	void	*win;

	int		width;
	int		height;
}				t_window;

typedef struct	s_player
{
	float	pos_x;
	float	pos_y;

	int		color;
}				t_player;

void	player_init(t_player *p, float x, float y, int color);
int		player_move(t_player *p, int key);
void	player_draw(t_player *p, t_window *win);
#endif

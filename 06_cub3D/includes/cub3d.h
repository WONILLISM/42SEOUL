#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "opengl/mlx.h"
# include "key.h"
# include "../GNL/get_next_line_bonus.h"
# include "../Libft/libft.h"
# define DEG2RAD		M_PI/180
# define RAD2DEG		180/M_PI

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct		s_img
{
	int				w;
	int				h;
	int				bpp;	//bit per pixel
	int				size_line;
	int				endian;
	void			*ptr;
	unsigned int	*addr;
	char			*path;
}					t_img;

typedef struct	s_player
{
    t_vec		pos;
	t_vec		dir;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct	s_screen
{
	double		screenX;
	double		distWall;
	t_vec		ray;
	t_vec		plane;
	t_vec		side;
	t_vec		delta;
	t_img		view;
	int			gridX;
	int			gridY;
	int			cellX;
	int			cellY;
	int			isHitSide;
	int			isHitWall;
}				t_screen;

typedef struct	s_key
{
    int			w;
    int			s;
    int			a;
    int			d;
	int			q;
	int			e;
	int			z;
	int			sft;
}				t_key;

typedef struct	s_archive
{
	int			width;
	int			height;

	t_mlx		m;
    t_player	p;
	t_screen	s;
	t_key		key;
	char		**map;
	int			row_size;
	int			col_size;
}				t_archive;

typedef struct	s_data
{
	t_archive	a;
	int		*north;
	int		*south;
	int		*west;
	int		*east;
	int		*sprite;
	int		floor_color;
	int		ceil_color;
}				t_data;

t_vec	new_vector(double x, double y);
t_vec	add_vector(t_vec a, t_vec b);
t_vec	sub_vector(t_vec a, t_vec b);
t_vec	mul_vector(t_vec v, double k);
t_vec	rot_vector(t_vec v, double angle);

void	xpm2img(t_data *game_d);

int	 cub3d(t_data *d);
#endif

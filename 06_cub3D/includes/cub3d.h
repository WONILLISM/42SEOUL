#ifndef _CUB3D_H_
# define _CUB3D_H_
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "opengl/mlx.h"
# include "key.h"
# include "libft/libft.h"

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

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_player
{
    t_vec		pos;
	t_vec		dir;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct	s_screen
{
	int			width;
	int			height;
	int			col_size;
	int			row_size;
	t_player	p;
	t_vec		plane;

	double		screenX;
	double		distWall;
	t_vec		ray;
	t_vec		side;
	t_vec		delta;
	t_img		view;
	int			gridX;
	int			gridY;
	int			cellX;
	int			cellY;
	int			isHitSide;
	int			isHitWall;
	char		**map_arr;

	void		*mlx;
	void		*win;
}				t_screen;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_bfs
{
	t_pos			cur;
	int				dx[4];
	int				dy[4];
	int				*chk;
	int				col;
	int				row;
	int				f;
	int				r;
}					t_bfs;

typedef struct	s_gamedata 
{
	t_screen	scrn;
	t_key		key;
	int			*north_img;
	int			*south_img;
	int			*east_img;
	int			*west_img;
	int			*sprite_img;
	int			ceil_color;
	int			floor_color;
}				t_gamedata;


int	 cub3d(t_gamedata *d);
/*
** ------------------ valid_map.c -----------------------
*/
void	find_player(t_gamedata *d, t_bfs *a);
int		process_bfs(t_gamedata *d, t_bfs *bf, t_pos *nxt, t_pos **q);
int		is_valid_map(t_gamedata *d);

/*
** ------------------ init_parse.c -----------------------
*/
void	init_bfs(t_gamedata *d, t_bfs *a);
void	init_gamedata(t_gamedata *d);
void	init_player(t_gamedata *d, t_bfs *a, int k);

/*
** ------------------ parse_gamedata_2.c -----------------------
*/
void	parse_map(char *line, t_list **map);
int		parse_color(char **res);
int		*parse_texture(t_gamedata *d, char *path);

/*
** ------------------ parse_gamedata_1.c -----------------------
*/
void	parse_resolution(t_gamedata *d, char **res);
int		parse_info(t_gamedata *d, char *line, char **res);
int		parse_gamedata(t_gamedata *d, char *path);

/*
** ------------------ parse_util.c -----------------------
*/
int		get_col_size(t_list *lst);
char	**lst2arr(t_gamedata *d, t_list *lst);
void	free_split(char **res);
void	free_gamedata(t_gamedata *d);

/*
**
*/
t_vec	new_vector(double x, double y);
t_vec	add_vector(t_vec a, t_vec b);
t_vec	sub_vector(t_vec a, t_vec b);
t_vec	mul_vector(t_vec v, double k);
t_vec	rot_vector(t_vec v, double rs);

#endif
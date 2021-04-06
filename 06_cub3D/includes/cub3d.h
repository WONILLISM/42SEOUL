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
}				t_vec;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;

typedef struct	s_player
{
    t_vec		pos;
	t_vec		dir;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct	s_sprites
{
	t_vec		sprt_pos;
	t_vec		transform;
	double		inv_det;

	int			scrnX;
	int			sprt_h;
	int			sprt_w;
	int			drawStartX;
	int			drawStartY;
	int			drawEndY;
	int			drawEndX;

	int			texX;
	int			texY;
	int			dist;
	int			color;
}				t_sprites;

typedef struct	s_texture
{
	double		wall;
	double		step;
	double		texPos;

	int			color;
	int			texX;
	int			texY;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}				t_texture;

typedef struct	s_screen
{
	int			width;
	int			height;
	int			col_size;
	int			row_size;
	t_player	p;
	t_vec		plane;

	double		*ZBuffer;
	int			*sprite_idx;
	int			numofsprt;
	t_sprite	*sprite;

	t_texture	tex;

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


int	 	cub3d(t_gamedata *d);
/*
** ------------------ valid_map.c -----------------------
*/
void	find_player_spirte(t_gamedata *d, t_bfs *a, int i, int j);
void	find_arguments(t_gamedata *d, t_bfs *a);
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
** ------------------ vec.c -----------------------
*/
t_vec	new_vector(double x, double y);
t_vec	add_vector(t_vec a, t_vec b);
t_vec	sub_vector(t_vec a, t_vec b);
t_vec	mul_vector(t_vec v, double k);
t_vec	rot_vector(t_vec v, double rs);

/*
** ------------------ sprite.c -----------------------
*/
void	init_sprite(t_screen *s);
void	proc_sprite(t_screen *s, int *img);

/*
** ------------------ sprite_util.c -----------------------
*/
void	init_sprite(t_screen *s);
void	sort_sprite(t_screen *s);

/*
** ------------------ init.c -----------------------
*/
void	init_keys(t_key *key);
void	init_screen(t_screen *s);

/*
** ------------------ key_manage.c -----------------------
*/
int		key_pressed(int key, t_key *key_info);
int		key_released(int key, t_key *key_info);
void	move_player(t_gamedata *d);

/*
** ------------------ ray_cast.c -----------------------
*/
void	loop_to_wall(t_screen *s);
void	draw_texture(t_screen *s, int *img, int x);
void	check_hit(t_gamedata *d, int x);
void	proc_dda(t_screen *s, int x);
void	ray_cast(t_gamedata *d);

#endif

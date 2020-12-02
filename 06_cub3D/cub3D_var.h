#ifndef _CUB3D_VAR_H_
# define _CUB3D_VAR_H_

/*************** mac OS key code **************/
# define _A	0
# define _S	1
# define _D	2
# define _F	3
# define _G	4
# define _H	5
# define _Z	6
# define _X	7
# define _C	8
# define _V	9
# define _B	11
# define _Q	12
# define _W	13
# define _E	14
# define _R	15
# define _Y	16
# define _T	17
# define _1	18
# define _2	19
# define _3	20
# define _4	21
# define _6	22
# define _5	23
# define _PLUS	24
# define _9	25
# define _7	26
# define _MINUS	27
# define _8	28
# define _0	29

# define _ESC 53
/*************** mac OS key code **************/
# define MAP_WIDTH	24
# define MAP_HEIGHT	24
# define PI			3.1415926535897
# define DEG2RAD	PI/180
# define RAD2DEG	180/PI

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "opengl/mlx.h"

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_player	p;

	int		screen_width;
	int		screen_height;
}				t_window;

typedef struct	s_img
{
	int		w;
	int		h;
	int		bit_per_pixel;
	int		size_line;
	int		endianl;
	void	*ptr;
	int		*obj_addr;
}				t_img;
typedef struct	s_player
{
	t_vec		pos;
	t_vec		dir;
	t_vec		cam_plane;

}				t_player;


void	*create_square(t_window *win, int w, int h, int fill);
t_vec	new_vector(double x, double y);
t_vec	vec_add(t_vec a, t_vec b);
t_vec	vec_sub(t_vec a, t_vec b);
t_vec	vec_mul(t_vec a, double b);
#endif

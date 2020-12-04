#ifndef _CUB3D_H_
# define _CUB3D_H_

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

typedef struct	s_img
{
	int		w;				// 너비(width)
	int		h;				// 높이(height)
	int		bit_per_pixel;	// 픽셀의 색상을 표현하는데 사용하는 비트 수
	int		size_line;		// 이미지 한 줄을 저장하는데 사용하는 바이트 수
	int		endian;			// 픽셀의 색상 방식
	void	*ptr;
	int		*obj_addr;
}				t_img;

typedef struct	s_player
{
	double		px;
	double		py;
}				t_player;


typedef struct	s_ray
{
	t_vec		dir;
	double		dist;
}				t_ray;

typedef struct	s_pixel
{
	double		dist;
	int			color;
}				t_pixel;

typedef struct  	s_screen{
	void			*mlx;
	void			*win;
	t_img			img;
	t_pixel			**pixel;
	t_vec			origin;
	t_vec			dir;
	t_vec			plane;
	double			sin_unit;
	double			cos_unit;
	double			distance;
	t_ray			*ray;
	int				w;
	int				h;
}					t_screen;

typedef struct		s_archive
{
	t_player		*p;
	t_screen		*screen;
	t_img			*player_img;
	t_img			*wall_img;
}					t_archive;

t_img	*create_square(t_archive *arcv, int w, int h, int fill);
t_vec	new_vector(double x, double y);
t_vec	vec_add(t_vec a, t_vec b);
t_vec	vec_sub(t_vec a, t_vec b);
t_vec	vec_mul(t_vec a, double b);
#endif

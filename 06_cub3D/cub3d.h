#ifndef _CUB3D_H_
# define _CUB3D_H_

/*************** mac OS key code **************/
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_F	3
# define KEY_G	4
# define KEY_H	5
# define KEY_Z	6
# define KEY_X	7
# define KEY_C	8
# define KEY_V	9
# define KEY_B	11
# define KEY_Q	12
# define KEY_W	13
# define KEY_E	14
# define KEY_R	15
# define KEY_Y	16
# define KEY_T	17
# define KEY_1	18
# define KEY_2	19
# define KEY_3	20
# define KEY_4	21
# define KEY_6	22
# define KEY_5	23
# define KEY_PLUS	24
# define KEY_9	25
# define KEY_7	26
# define KEY_MINUS	27
# define KEY_8	28
# define KEY_0	29
# define KEY_ESC 53
/*************** mac OS key code **************/

# define PI			3.1415926535897
# define DEG2RAD	PI/180
# define RAD2DEG	180/PI

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "includes/opengl/mlx.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_player
{
    int			x;
    int			y;
    int			dir;
}				t_player;

typedef struct	s_key
{
    int			w;
    int			s;
    int			a;
    int			d;
	int			q;
	int			e;
}				t_key;

typedef struct	s_archive
{
	int			width;
	int			height;

	t_mlx		m;
    t_player	p;
	t_key		key;
}				t_archive;
#endif
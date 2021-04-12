#include "../../includes/cub3d.h"

int		key_pressed(int key, t_key *key_info)
{
	if (key == KEY_W)
		key_info->w = 1;
	else if (key == KEY_S)
		key_info->s = 1;
	else if (key == KEY_A)
		key_info->a = 1;
	else if (key == KEY_D)
		key_info->d = 1;
	else if (key == KEY_UP)
		key_info->up = 1;
	else if (key == KEY_DOWN)
		key_info->down = 1;
	else if (key == KEY_LEFT)
		key_info->left = 1;
	else if (key == KEY_RIGTH)
		key_info->right = 1;
	else if (key == KEY_ESC)
		ft_exit();
	return (0);
}

int		key_released(int key, t_key *key_info)
{
	if (key == KEY_W)
		key_info->w = 0;
	else if (key == KEY_S)
		key_info->s = 0;
	else if (key == KEY_A)
		key_info->a = 0;
	else if (key == KEY_D)
		key_info->d = 0;
	else if (key == KEY_UP)
		key_info->up = 0;
	else if (key == KEY_DOWN)
		key_info->down = 0;
	else if (key == KEY_LEFT)
		key_info->left = 0;
	else if (key == KEY_RIGTH)
		key_info->right = 0;
	return (0);
}

void	move_player(t_gamedata *d, t_vec dir,int sub_add)
{
	t_vec	np;

	if (sub_add == 0)
		np = sub_vector(d->scrn.p.pos, mul_vector(dir, d->scrn.p.move_speed));
	else if (sub_add == 1)
		np = add_vector(d->scrn.p.pos, mul_vector(dir, d->scrn.p.move_speed));
	if (d->scrn.map_arr[(int)(d->scrn.p.pos.y)][(int)(np.x)] == '0')
			d->scrn.p.pos.x = np.x;
	if (d->scrn.map_arr[(int)(np.y)][(int)(d->scrn.p.pos.x)] == '0')
		d->scrn.p.pos.y = np.y;
}

void	rotate_player(t_gamedata *d, int sign)
{
	d->scrn.p.dir = rot_vector(d->scrn.p.dir, sign * d->scrn.p.rot_speed);
	d->scrn.plane = rot_vector(d->scrn.plane, sign * d->scrn.p.rot_speed);
}

void	manage_player(t_gamedata *d)
{
	t_vec	np;

	if (d->key.w || d->key.up)
		move_player(d, d->scrn.p.dir, 1);
	else if (d->key.s || d->key.down)
		move_player(d, d->scrn.p.dir, 0);
	else if (d->key.left)
		rotate_player(d, -1);
	else if (d->key.right)
		rotate_player(d, 1);
	else if (d->key.a)
		move_player(d, rot_vector(d->scrn.p.dir, M_PI/2), 0);
	else if (d->key.d)
		move_player(d, rot_vector(d->scrn.p.dir, M_PI/2), 1);
}

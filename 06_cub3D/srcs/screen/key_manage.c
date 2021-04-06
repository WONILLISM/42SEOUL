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
	else if (key == KEY_Q)
		key_info->q = 1;
	else if (key == KEY_E)
		key_info->e = 1;
	else if (key == KEY_Z){
		if (key_info->z == 1)
			key_info->z = 0;
		else
			key_info->z = 1;
	}
	else if (key == KEY_SHIFT)
		key_info->sft = 1;
	else if (key == KEY_ESC)
		exit(0);
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
	else if (key == KEY_Q)
		key_info->q = 0;
	else if (key == KEY_E)
		key_info->e = 0;
	else if (key == KEY_SHIFT)
		key_info->sft = 0;
	return (0);
}

void	move_player(t_gamedata *d)
{
	t_vec	np;

	if (d->key.w)
	{
		np = add_vector(d->scrn.p.pos, mul_vector(d->scrn.p.dir, d->scrn.p.move_speed));
		if (d->scrn.map_arr[(int)(d->scrn.p.pos.y)][(int)(np.x)] == '0')
			d->scrn.p.pos.x = np.x;
		if (d->scrn.map_arr[(int)(np.y)][(int)(d->scrn.p.pos.x)] == '0')
			d->scrn.p.pos.y = np.y;
	}
	else if (d->key.s)
	{
		np = add_vector(d->scrn.p.pos, mul_vector(d->scrn.p.dir, -1 * d->scrn.p.move_speed));
		if (d->scrn.map_arr[(int)(d->scrn.p.pos.y)][(int)(np.x)] == '0')
			d->scrn.p.pos.x = np.x;
		if (d->scrn.map_arr[(int)(np.y)][(int)(d->scrn.p.pos.x)] == '0')
			d->scrn.p.pos.y = np.y;
	}
	else if (d->key.a)
	{
		d->scrn.p.dir = rot_vector(d->scrn.p.dir, -1.0f * d->scrn.p.rot_speed);
		d->scrn.plane = rot_vector(d->scrn.plane, -1.0f * d->scrn.p.rot_speed);
	}
	else if (d->key.d)
	{
		d->scrn.p.dir = rot_vector(d->scrn.p.dir, d->scrn.p.rot_speed);
		d->scrn.plane = rot_vector(d->scrn.plane, d->scrn.p.rot_speed);
	}
}
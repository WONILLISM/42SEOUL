#include "../../includes/cub3d.h"

void	loop_to_wall(t_screen *s)
{
	while (!s->isHitWall)
	{
		if (s->side.x < s->side.y)
		{
			s->side.x += s->delta.x;
			s->gridX += s->cellX;
			s->isHitSide = 0;
		}
		else
		{
			s->side.y += s->delta.y;
			s->gridY += s->cellY;
			s->isHitSide = 1;
		}
		if (s->map_arr[s->gridY][s->gridX]=='1')
			s->isHitWall = 1;
	}
}

void	draw_texture(t_screen *s, int *img, int x)
{
	s->tex.lineHeight = (int)(s->height / s->distWall);
	s->tex.drawStart = -s->tex.lineHeight / 2 + s->height / 2;
	s->tex.drawEnd = s->tex.lineHeight / 2 + s->height / 2;
	if (s->tex.drawStart < 0)
		s->tex.drawStart = 0;
	if (s->tex.drawEnd >= s->height)
		s->tex.drawEnd = s->height - 1;
	if (s->isHitSide == 1)
		s->tex.wall = s->p.pos.x + s->distWall * s->ray.x;
	else
		s->tex.wall = s->p.pos.y + s->distWall * s->ray.y;
	s->tex.wall -= floor(s->tex.wall);
	s->tex.texX = (int)(s->tex.wall * (double)64);
	if (s->isHitSide == 0 && s->ray.x < 0)
		s->tex.texX = 64 - s->tex.texX - 1;
	if (s->isHitSide == 1 && s->ray.y > 0)
		s->tex.texX = 64 - s->tex.texX - 1;
	s->tex.step = 1.0 * 64 / s->tex.lineHeight;
	s->tex.texPos = (s->tex.drawStart - s->height / 2 + s->tex.lineHeight / 2) * s->tex.step;
	while (s->tex.drawStart < s->tex.drawEnd)
	{
		s->tex.texY = (int)s->tex.texPos & (64 - 1);
		s->tex.texPos += s->tex.step;
		s->view.addr[s->width * s->tex.drawStart + x] = img[64 * s->tex.texY + s->tex.texX];
		s->tex.drawStart++;
	}
}

void	check_hit(t_gamedata *d, int x)
{
	t_screen	*s;

	s = &d->scrn;
	s->delta.x = fabs(1 / s->ray.x);
	s->delta.y = fabs(1 / s->ray.y);
	s->isHitWall = 0;
	loop_to_wall(s);
	if (!s->isHitSide)
	{
		if (s->ray.x > 0){
			draw_texture(s, d->east_img, x);
		}
		else
			draw_texture(s, d->west_img, x);
		s->distWall = (s->gridX - s->p.pos.x + (1 - s->cellX) / 2 ) / s->ray.x;
	}
	else
	{
		if (s->ray.y > 0)
			draw_texture(s, d->south_img,x);
		else
			draw_texture(s, d->north_img, x);
		s->distWall = (s->gridY - s->p.pos.y + (1 - s->cellY) / 2 ) / s->ray.y;
	}
	s->ZBuffer[x] = s->distWall;
}

void	proc_dda(t_screen *s, int x)
{
	s->screenX = 2 * x / (double)s->width - 1;
	s->ray = add_vector(s->p.dir, mul_vector(s->plane, s->screenX));
	s->gridX = (int)(s->p.pos.x);
	s->gridY = (int)(s->p.pos.y);
	if (s->ray.x < 0)
	{
		s->cellX = -1;
		s->side.x = (s->p.pos.x - s->gridX) * s->delta.x;
	}
	else
	{
		s->cellX = 1;
		s->side.x = (s->gridX + 1.0f - s->p.pos.x) * s->delta.x;
	}

	if (s->ray.y < 0)
	{
		s->cellY = -1;
		s->side.y = (s->p.pos.y - s->gridY) * s->delta.y;
	}
	else
	{
		s->cellY = 1;
		s->side.y = (s->gridY + 1.0f - s->p.pos.y) * s->delta.y;
	}
}

void	ray_cast(t_gamedata *d)
{
	t_screen	*s;
	int			x;

	s = &d->scrn;
	x = 0;
	while (x < s->width)
	{
		proc_dda(s, x);
		check_hit(d, x);
		x++;
	}
	proc_sprite(s, d->sprite_img);
}
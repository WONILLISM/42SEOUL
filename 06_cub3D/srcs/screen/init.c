#include "../../includes/cub3d.h"

void	init_keys(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->q = 0;
	key->e = 0;
}

void	init_screen(t_screen *s)
{
	s->ZBuffer = (double *)malloc(sizeof(double) * s->width);
	s->screenX = 0;
	s->distWall = 0;
	s->ray.x = 0.0f;
	s->ray.y = 0.0f;
	s->side.x = 0.0f;
	s->side.y = 0.0f;
	s->delta.x = 0.0f;
	s->delta.y = 0.0f;
	s->gridX = 0;
	s->gridY = 0;
	s->cellX = 0;
	s->cellY = 0;
	s->isHitSide = 0;
	s->isHitWall = 0;
}
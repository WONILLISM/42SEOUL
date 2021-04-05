#include "../../includes/cub3d.h"

void	init_sprite(t_screen *s)
{
	int		i;
	int		j;
	int		idx;

	idx = 0;
	i = -1;
	while (++i < s->row_size)
	{
		j = -1;
		while (++j < s->col_size)
		{
			if (s->map_arr[i][j] == '2')
			{
				// printf("%d %d\n", i, j);
				s->sprite[idx].y = (double)i + 0.5;
				s->sprite[idx].x = (double)j + 0.5;
				idx++;
			}
		}
	}
}

void	sort_sprite(t_screen *s)
{
	double		tmp;
	int			idx_tmp;
	int			i;
	int			j;

	i = 0;
	while (i < s->numofsprt)
	{
		j = i;
		while (j < s->numofsprt)
		{
			if (s->sprite[i].dist < s->sprite[j].dist)
			{
				tmp = s->sprite[j].dist;
				s->sprite[j].dist = s->sprite[i].dist;
				s->sprite[i].dist = tmp;
				idx_tmp = s->sprite[j].idx;
				s->sprite[j].idx = s->sprite[i].idx;
				s->sprite[i].idx = idx_tmp;

			}
			j++;
		}
		i++;
	}
}
void	proc_sprite(t_gamedata *d)
{
	t_screen	*s;
	int		i;

	s = &d->scrn;
	i = 0;
	while (i < s->numofsprt)
	{
		s->sprite[i].idx = i;
		s->sprite[i].dist = ((s->p.pos.x - s->sprite[i].x) * (s->p.pos.x - s->sprite[i].x) + (s->p.pos.y - s->sprite[i].y) * (s->p.pos.y - s->sprite[i].y));
		i++;
	}
	sort_sprite(s);
	i = 0;
	while (i < s->numofsprt)
	{
		printf("i : %d %f\n",i,  s->sprite[i].dist);
		double	spriteX = s->sprite[i].x - s->p.pos.x;
		double	spriteY = s->sprite[i].y - s->p.pos.y;
		double	invDet = 1.0 / (s->plane.x * s->p.dir.y - s->p.dir.x * s->plane.y);

		double transformX = invDet * (s->p.dir.y * spriteX - s->p.dir.x * spriteY);
		double transformY = invDet * (-s->plane.y * spriteX + s->plane.x * spriteY);


		int spriteScreenX = (int)((s->width / 2) * (1 + transformX / transformY));
		int spriteHeight = abs((int)(s->height / (transformY)));
		int drawStartY = -spriteHeight / 2 + s->height / 2;
		if (drawStartY < 0)
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + s->height / 2;
		if (drawEndY >= s->height)
			drawEndY = s->height - 1;

		//calculate width of the sprite
		int spriteWidth = abs((int)(s->height / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0)
			drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= s->width)
			drawEndX = s->width - 1;

		//loop through every vertical stripe of the sprite on screen
		for (int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (transformY > 0 && stripe > 0 && stripe < s->width && transformY < s->ZBuffer[stripe])
				for (int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
				{
					int dist = (y)*256 - s->height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					int texY = ((dist * 64) / spriteHeight) / 256;
					int color = d->sprite_img[64 * texY + texX];;
					if ((color & 0x00FFFFFF) != 0)
						s->view.addr[y * s->width + stripe] = color; //paint pixel if it isn't black, black is the invisible color
				}
		}

		i++;
	}
}

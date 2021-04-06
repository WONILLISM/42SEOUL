#include "../../includes/cub3d.h"

void	find_player_spirte(t_gamedata *d, t_bfs *a, int i, int j)
{
	int		k;
	char	*spec;

	spec = "ESWN";
	k = 0;
	if (d->scrn.map_arr[i][j] == '2')
	{
		d->scrn.numofsprt++;
	}
	while (spec[k])
	{
		if (d->scrn.map_arr[i][j] == spec[k])
		{
			a->cur.y = i;
			a->cur.x = j;
			init_player(d, a, k);
			d->scrn.map_arr[i][j] = '0';
		}
		k++;
	}
}
void	find_arguments(t_gamedata *d, t_bfs *a)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < a->row)
	{
		j = -1;
		while (++j < a->col)
		{
			find_player_spirte(d, a, i, j);
		}
	}
	d->scrn.sprite = (t_sprite *)malloc(sizeof(t_sprite) * d->scrn.numofsprt);
}

int		process_bfs(t_gamedata *d, t_bfs *bf, t_pos *nxt, t_pos **q)
{
	int		i;

	i = 0;
	while (++i < 4)
	{
		nxt->y = bf->cur.y + bf->dy[i];
		nxt->x = bf->cur.x + bf->dx[i];
		if ((nxt->y >= 0 && nxt->y < bf->row && nxt->x >= 0 && nxt->x < bf->col) && bf->chk[nxt->y * bf->col + nxt->x] == 0)
		{
			if (d->scrn.map_arr[nxt->y][nxt->x] == '0')
			{
				bf->chk[nxt->y * bf->col + nxt->x] = 1;
				(*q)[bf->r++] = *nxt;
			}
			if (d->scrn.map_arr[nxt->y][nxt->x] == ' ')
			{
				bf->chk[nxt->y * bf->col + nxt->x] = 9;
				return (1);
			}
		}
	}
	return (0);
}

int		is_valid_map(t_gamedata *d)
{
	t_pos	*q;
	t_pos	nxt;
	t_bfs	bf;
	int		i;
	int		flag;

	init_bfs(d, &bf);
	flag = 0;
	q = (t_pos *)malloc(sizeof(t_pos) * bf.row * bf.col);
	q[bf.r++] = bf.cur;
	while (bf.f != bf.r && !flag)
	{
		bf.cur = q[bf.f++];
		i = -1;
		flag = process_bfs(d, &bf, &nxt, &q);
	}
	free(bf.chk);
	free(q);
	if (!flag)
		return (0);
	else
		return (-1);
}

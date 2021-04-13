#include "../../includes/cub3d.h"

void	chk_player_pos(t_gamedata *d,t_bfs *a, int i, int j)
{
	int		k;
	char	tmp;

	k = 0;
	if (i == 0 || j == 0 || i == a->row -1 || i == a->col - 1)
		error_message("player pos", d);
	while (k < 4)
	{
		tmp = d->scrn.map_arr[i + a->dy[k]][j + a->dx[k]];
		if (tmp == ' ' || tmp == '\0')
			error_message("player pos", d);
		k++;
	}
}
void	find_player_spirte(t_gamedata *d, t_bfs *a, int i, int j)
{
	int		k;
	char	*spec;

	spec = "ESWN";
	k = 0;
	if (d->scrn.map_arr[i][j] == '2')
		d->scrn.numofsprt++;
	while (spec[k])
	{
		if (d->scrn.map_arr[i][j] == spec[k])
		{
			a->cur.y = i;
			a->cur.x = j;
			chk_player_pos(d,a,i,j);
			init_player(d, a, k);
			d->scrn.map_arr[i][j] = '0';
			a->is_empty_player++;
		}
		k++;
	}
}
int		find_arguments(t_gamedata *d, t_bfs *a)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < a->row)
	{
		j = -1;
		while (++j < a->col)
			find_player_spirte(d, a, i, j);
	}
	d->scrn.sprite = (t_sprite *)malloc(sizeof(t_sprite) * d->scrn.numofsprt);
	return (a->is_empty_player);
}

int		process_bfs(t_gamedata *d, t_bfs *bf, t_pos **q)
{
	t_pos	nxt;
	int		i;

	i = 0;
	while (i < 4)
	{
		nxt.y = bf->cur.y + bf->dy[i];
		nxt.x = bf->cur.x + bf->dx[i];
		if ((nxt.y >= 0 && nxt.y < bf->row && nxt.x >= 0 && nxt.x < bf->col) && bf->chk[nxt.y * bf->col + nxt.x] == 0)
		{
			if (d->scrn.map_arr[nxt.y][nxt.x] == '0' || d->scrn.map_arr[nxt.y][nxt.x] == '2')
			{
				if (nxt.y == 0 || nxt.x == 0 || nxt.y == (bf->row -1) || nxt.x == (bf->col -1))
					return (1);
				bf->chk[nxt.y * bf->col + nxt.x] = 1;
				(*q)[bf->r++] = nxt;
			}
			else if (d->scrn.map_arr[nxt.y][nxt.x] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

int		is_valid_map(t_gamedata *d)
{
	t_pos	*q;
	t_bfs	bf;
	int		flag;

	init_bfs(d, &bf);
	flag = 0;
	q = (t_pos *)malloc(sizeof(t_pos) * bf.row * bf.col);
	q[bf.r++] = bf.cur;
	bf.chk[bf.cur.y * bf.col + bf.cur.x] = 1;
	while (bf.f != bf.r && !flag)
	{
		bf.cur = q[bf.f++];
		flag = process_bfs(d, &bf, &q);
	}
	free(bf.chk);
	free(q);
	return (flag);
}

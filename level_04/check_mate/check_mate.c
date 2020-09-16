#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_pos{
	int y;
	int x;
	int step;
} t_pos;

// int **check;
t_pos king = {-10, -10};
t_pos dir[8] = {{0,1}, {1,0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int g_n;

int is_chess_pieces(char c)
{
	return (c == 'P' || c == 'Q' || c == 'R' || c =='B');
}
int dfs(int d,t_pos cur, char **chess)
{
	t_pos next;
	if (cur.step == 2)
	{
		if ((d>=0 && d<=3) && (chess[cur.y][cur.x] == 'R' || chess[cur.y][cur.x] == 'Q'))
			return (1);
		if ((d>=4 && d<=7) && (chess[cur.y][cur.x] == 'B' || chess[cur.y][cur.x] == 'Q'))
			return (1);
	}
	
	next.y = cur.y + dir[d].y;
	next.x = cur.x + dir[d].x;
	if (next.y >= 0 && next.y < g_n && next.x >= 0 && next.x < g_n)
	{
		if (is_chess_pieces(chess[next.y][next.x]))
			next.step = cur.step + 1;
		else 
			next.step = cur.step;
		
		return dfs(d, next, chess);
	}
	return (0);
}

int ft_check_mate(char **chess)
{
	int i;
	int j;
	t_pos p_pos;

	i = 0;
	while (i < g_n)
	{
		j = 0;
		while (j < g_n)
		{
			if (chess[i][j] == 'K')
			{
				king.y = i;
				king.x = j;
				king.step = 1;
			}
			if (chess[i][j] == 'P'){
				p_pos.y = i;
				p_pos.x = j;
			}
			j++;
		}
		i++;
	}
	if (((p_pos.y - 1 == king.y) && (p_pos.x - 1 == king.x)) ||((p_pos.y - 1 == king.y) && (p_pos.x + 1 == king.x)))
		return (1);
	i = 0;
	while (i < 8)
	{
		if (dfs(i, king, chess))
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	g_n = argc - 1;
	if(argc > 1){
		if (ft_check_mate(&argv[1]))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);	
	return (0);
}
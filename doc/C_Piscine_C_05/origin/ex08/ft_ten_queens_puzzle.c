#include <stdio.h>
#include <unistd.h>

int		g_row[10];      // 각 행에 대해 퀸이 들어올 수 있는 칸을 체크
int		g_right_up[20]; // 퀸이 놓였을 때 우상향 대각선 부분을 체크
int		g_left_up[20];  // 퀸이 놓였을 때 좌상향 대각선 부분을 체크
int		g_cnt;          // 10개의 퀸을 놓을 수 있는 경우의 수
char	g_ans[11];      // 퀸이 놓인 위치를 반환하기 위한 배열

void	process(int r)
{
	int i;

	if (r == 10)    // 모든 행을 탐색했을 때 = 10개의 퀸을 모두 놓았을 때
	{
		g_cnt++;
		write(1, g_ans, 10);    // 퀸의 위치 출력
		write(1, "\n", 1);
		return ;    // 함수 종료
	}
	i = 0;  // r행 i열
	while (i < 10)
	{
		if (!g_row[i] && !g_right_up[r + i] && !g_left_up[10 + (r - i) - 1])    // 해당 체크 배열이 비어있을 때 = 퀸을 놓을 수 있는 자리
		{
			g_row[i] = 1;                       // 퀸을 놓고 해당 i열에 체크, 우상향, 좌상향 대각선에 체크
			g_right_up[r + i] = 1;
			g_left_up[10 + (r - i) - 1] = 1;
			g_ans[r] = i + '0';
			process(r + 1);         // 재귀 -> 다음 행에 대하여 탐색
			g_row[i] = 0;               // 재귀 함수를 탈출하면 이전에 체크되었던 배열들을 해제
			g_right_up[r + i] = 0;
			g_left_up[10 + (r - i) - 1] = 0;
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	process(0);
	return (g_cnt);
}

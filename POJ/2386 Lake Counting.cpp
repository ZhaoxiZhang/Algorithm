#include<stdio.h>
#define MAX_N 105
#define MAX_M 105
char field[MAX_N][MAX_M];
int N,M;


void dfs(int x,int y)
{
	
	int dx,dy,nx,ny;
	
	field[x][y] = '.'; //将现在位置替换为'.'; 
	
	for (dx = -1;dx < 2;dx++)  //遍历移动的8个方向 
	{
		for (dy = -1;dy < 2;dy++)
		{
			nx = x + dx,ny = y + dy;
			if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W')
			{                                   //判断(nx,ny)是不是在园子内 
				dfs(nx,ny);
			}
		}
	}
}


int main()
{
	int i,j,res = 0;
	char tmp;
	scanf("%d%d",&N,&M);
	getchar();
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
		{
			scanf("%c",&field[i][j]);
			if (j==M-1)
			{
				scanf("%c",&tmp);
			}
		}
	}
	
	for (i = 0;i < N;i++)
	{
		for (j = 0;j < M;j++)
		{
			if (field[i][j] == 'W')
			{
				dfs(i,j);
			    res++;
			}
		}
	}
	
	printf("%d\n",res);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		int res = 0;
		char maze[15][15];
		int dx[4] = {-1,0,1,0};
		int dy[4] = {0,-1,0,1};
		for (int i = 0;i < N;i++)
		{
			scanf("%s",maze[i]);
		}
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < M;j++)
			{
				if (maze[i][j] == 'W')
				{
					for (int ii = 0;ii < 4;ii++)
					{
						int nx = dx[ii] + i;
						int ny = dy[ii] + j;
						if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == 'P')
						{
							res++;
							maze[nx][ny] = '.';
							break;
						}
					}
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}


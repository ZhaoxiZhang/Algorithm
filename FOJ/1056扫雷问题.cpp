#include<stdio.h>
const int MAX_M = 105;
const int MAX_N = 105;
char ans[MAX_M][MAX_N];

int main()
{
	int M,N,nx,ny,dx,dy,i,j,cnt;

	while (scanf("%d%d",&M,&N) != EOF)
	{
		if (M == 0 && N == 0)
		{
			return 0;
		}
		else
		{

			for (i = 0; i < M; i++)
			{
				scanf("%s",ans[i]);
			}

			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)
				{
					if (ans[i][j] == '*')
					{
						printf("*");
					}
					else
					{
						cnt = 0;
						for (dx = -1; dx < 2; dx++)
						{
							for (dy = -1; dy < 2; dy++)
							{
								nx = i + dx;
								ny = j + dy;
								if (nx >= 0 && nx < M && ny >= 0 && ny < N && ans[nx][ny] == '*')
								{
									cnt++;
								}
							}
						}
						printf("%d",cnt);
					}
				}
				printf("\n");
			}
			printf("\n");
		}
	}

	return 0;
}

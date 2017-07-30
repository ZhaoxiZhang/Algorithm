#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	int n,m;
	char maze[105][105];
	while (~scanf("%d%d",&n,&m))
	{
		memset(maze,0,sizeof(maze));
		for (int i = 0;i < n;i++)
		{
			getchar();
			for (int j = 0;j < m;j++)
			{
				scanf("%c",&maze[i][j]);
			}
		}
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (maze[i][j] == '-')
				{
					printf("%c",maze[i][j]);
				}
				else if (i % 2 == 0 && j % 2 == 0)
				{
					printf("B");
				}
				else if (i % 2 == 0 && j % 2 == 1)
				{
					printf("W");
				}
				else if (i % 2 == 1 && j % 2 == 0)
				{
					printf("W");
				}
				else if (i % 2 == 1 && j % 2 == 1)
				{
					printf("B");
				}
			}
			printf("\n");
		} 
	}
	return 0;
}

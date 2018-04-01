#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 15;
char maze[maxn][maxn];
int vis[maxn];
int n,k,cnt;

void dfs(int cur,int row)
{
	if (row > n)	return;
	if (cur == k)
	{
		cnt++;
		return;
	}
	else
	{
		for (int i = 0;i < 2;i++)        //每行可以选择放或者不放 
		{
			if (!i)	dfs(cur,row + 1);    //当行不放 
			else                         //当行放 
			{
				for (int j = 0;j < n;j++)
				{
					if (maze[row][j] == '#' && !vis[j])
					{
						vis[j] = 1;
						dfs(cur + 1,row + 1);
						vis[j] = 0;
					}	
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while (~scanf("%d%d",&n,&k) && n != -1 && k != -1)
	{
		cnt = 0;
		memset(maze,0,sizeof(maze));
		memset(vis,0,sizeof(vis));
		for (int i = 0;i < n;i++)	scanf("%s",maze[i]);
		dfs(0,0);
		printf("%d\n",cnt);
	}
	return 0;
}

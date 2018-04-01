#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_V = 105;
int edge[MAX_V][MAX_V];
int dis[MAX_V];
bool vis[MAX_V];
int N;

int prim()
{
	memset(dis,INF,sizeof(dis));
	memset(vis,false,sizeof(vis));
	for (int i = 1;i <= N;i++)
	{
		dis[i] = edge[i][1];
	}
	dis[1] = 0;
	vis[1] = true;
	int sum = 0;
	for (int i = 1;i < N;i++)
	{
		int tmp = INF,pos;
		for (int j = 1;j <= N;j++)
		{
			if(!vis[j] && tmp > dis[j])
			{
				tmp = dis[j];
				pos = j;
			}
		}
		if (tmp == INF) return 0;
		vis[pos] = true;
		sum += dis[pos];
		for(int j = 1;j <= N;j++)
		{
			if (!vis[j] && edge[pos][j] < dis[j])
			{
				dis[j] = edge[pos][j];
			}
		}
	}
	return sum;
}


int main()
{
	while (~scanf("%d",&N))
	{
		for (int i = 1;i <= N;i++)
		{
			for (int j = 1;j <= N;j++)
			{
				scanf("%d",&edge[i][j]);
			}
		}
		int res = prim();
		printf("%d\n",res);
	}
	return 0;
}

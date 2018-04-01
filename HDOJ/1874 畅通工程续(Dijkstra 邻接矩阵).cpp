#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 205;
const int INF = 0x3f3f3f3f;
int edge[MAX][MAX];

void Dijkstra(int s,int t,int n)
{
	bool vis[MAX];
	int dis[MAX];
	int min,pos;
	memset(vis,false,sizeof(vis));
	for (int i = 0;i < n;i++)
	{
		dis[i] = edge[s][i];
	}
	for (int i = 1;i < n;i++)
	{
		min = INF;
		for (int j = 0;j < n;j++)
		{
			if (dis[j] < min && !vis[j])
			{
				pos = j;
				min = dis[j];
			}
		}
		vis[pos] = true;
		for (int j = 0;j < n;j++)
		{
			if (dis[pos] + edge[pos][j] < dis[j])
			{
				dis[j] = dis[pos] + edge[pos][j];
			}
		}
	}
	printf("%d\n",dis[t] == INF?-1:dis[t]);
}


int main()
{
	int N,M,S,T;
	while (~scanf("%d%d",&N,&M))
	{
		int u,v,w;
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < i;j++)
			{
				if (i == j)edge[i][j] = edge[j][i] = 0;
				else edge[i][j] = edge[j][i] = INF;
			}
		}
		for (int i = 0;i < M;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			if (w < edge[u][v])
			{
				edge[u][v] = edge[v][u] = w;
			}
		}
		scanf("%d%d",&S,&T);
		Dijkstra(S,T,N);
	}
	return 0;
}

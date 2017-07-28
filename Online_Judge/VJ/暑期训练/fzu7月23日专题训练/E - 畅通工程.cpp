#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_V = 105;
int edge[MAX_V][MAX_V];
int dis[MAX_V];
bool vis[MAX_V];
int N,M;

int prim()
{
	memset(vis,false,sizeof(vis));
	memset(dis,INF,sizeof(dis));
	for (int i = 1;i <= M;i++)
	{
		dis[i] = edge[1][i];
	} 
	dis[1] = 0;
	vis[1] = true;
	int tmp,res = 0,pos;
	for (int i = 1;i <= M - 1;i++)
	{
		tmp = INF; 
		for (int j = 1;j <= M;j++)
		{
			if (!vis[j] && tmp > dis[j])
			{
				tmp = dis[j];
				pos = j;
			}
		}
		if (tmp == INF) return 0;
		vis[pos] = true;
		res += dis[pos];
		for (int j = 1;j <= M;j++)
		{
			if (!vis[j] && edge[pos][j] < dis[j] && edge[pos][j] != INF)
			{
				dis[j] = edge[pos][j];
			}
		}
	}
	return res;
}



int main()
{
	while (~scanf("%d%d",&N,&M) && N)
	{
		int u,v,w;
		/*for (int i = 0;i <= M;i++)
		{
			for (int j = 0;j <= i;j++)
			{
				if (i == j)	edge[i][j] = edge[j][i] = 0;
				else edge[i][j] = edge[j][i] = INF;
			}
		}*/
		memset(edge,INF,sizeof(edge));
		for (int i = 0;i <= M;i++)
		{
			edge[i][i] = 0; 
		}
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			if (w < edge[u][v])
			{
				edge[u][v] = edge[v][u] = w;
			}
		}
		int res = prim();
		res?printf("%d\n",res):printf("?\n");
	}
	return 0;
} 

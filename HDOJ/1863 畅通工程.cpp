#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const int INF = 0x3f3f3f3f;
const int MAX = 105;
int edge[MAX][MAX],dis[MAX];
bool vis[MAX];
int N,M;

int prim()
{
	int tmp,pos,res = 0;
	memset(vis,false,sizeof(vis));
	//memset(dis,INF,sizeof(dis));
	for (int i = 1;i <= M;i++)
	{
		dis[i] = edge[1][i];
	}
	dis[1] = 0;
	vis[1] = true;
	for (int i = 2;i <= M;i++)
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
		if (tmp == INF)	return 0;
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
		memset(edge,INF,sizeof(edge));
		for (int i = 0;i <= M;i++)
		{
			edge[i][i] = INF;
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

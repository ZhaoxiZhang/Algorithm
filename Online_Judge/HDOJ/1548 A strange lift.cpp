#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 205;
int edge[MAX][MAX],dis[MAX];
bool vis[MAX];
int N,A,B;

void Dijkstra()
{
	int tmp,pos;
	memset(vis,false,sizeof(vis));
	for (int i = 1;i <= N;i++)
	{
		dis[i] = edge[A][i];
	}
	dis[A] = 0;
	vis[A] = true;
	for (int i = 2;i <= N;i++)
	{
		tmp = INF;
		for (int j = 1;j <= N;j++)
		{
			if (!vis[j] && dis[j] < tmp)
			{
				tmp = dis[j];
				pos = j;
			}
		}
		if (tmp == INF)	break;
		vis[pos] = true;
		for (int j = 1;j <= N;j++)
		{
			if (dis[pos] + edge[pos][j] < dis[j])
			{
				dis[j] = dis[pos] + edge[pos][j];
			}
		}
	}
	printf("%d\n",dis[B] == INF?-1:dis[B]);
}


int main()
{
	while (~scanf("%d",&N) && N)
	{
		int tmp;
		memset(edge,INF,sizeof(edge));
		for (int i = 0;i <= N;i++)
		{
			for (int j = 0;j <= i;j++)
			{
				if (i == j)	edge[i][j] = edge[j][i] = 0;
				else	edge[i][j] = edge[j][i] = INF;
			}
		}
		scanf("%d%d",&A,&B);
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&tmp);
			if (i - tmp > 0)
			{
				edge[i][i-tmp] = 1;
			}
			if (i + tmp <= N)
			{
				edge[i][i+tmp] = 1;
			}
		}
		Dijkstra();
	}
	return 0;
}

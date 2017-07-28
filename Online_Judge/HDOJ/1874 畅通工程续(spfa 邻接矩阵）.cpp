#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 1005;
int edge[MAX][MAX];

void spfa(int s,int n,int t)
{
	int dis[MAX];
	bool vis[MAX];
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	queue<int>que;
	dis[s] = 0;
	que.push(s);
	vis[s] = true;
	while (!que.empty())
	{
		int curval = que.front();
		que.pop();
		vis[curval] = false;
		for (int i = 0;i < n;i++)
		{
			if (dis[curval] < dis[i] - edge[curval][i])
			{
				dis[i] = dis[curval] + edge[curval][i];
				if (!vis[i])
				{
					que.push(i);
					vis[i] = true;
				}
			}
		}
	}
	printf("%d\n",dis[t] == INF?-1:dis[t]);
}


int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		int u,v,w,S,T;
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < i;j++)
			{
				if (i == j) edge[i][j] = 0;
				else edge[i][j] = edge[j][i] = INF;
			}
		}
		for (int i =0;i < M;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			edge[u][v] = edge[v][u] = min(w,edge[u][v]);
		}
		scanf("%d%d",&S,&T);
		spfa(S,N,T);
	}
	return 0;
} 

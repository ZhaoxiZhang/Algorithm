#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int INF =  0x3f3f3f3f;
const int MAX_N = 1005;
bool flag[MAX_N];
int  edge[MAX_N][MAX_N];

void spfa(int n)
{
	int dis[MAX_N];
	queue<int>que;
	memset(flag,false,sizeof(flag));
	memset(dis,0x3f3f3f3f,sizeof(dis));
	
	dis[1] = 0;
	que.push(1);
	flag[1] = true;
	
	while (!que.empty())
	{
		int curval = que.front();
		que.pop();
		flag[curval] = false;
		
		for (int i = 1;i <= n;i++)
		{
			if (dis[curval] < dis[i] - edge[curval][i])
			{
				dis[i] = dis[curval] + edge[curval][i];
				
				if (!flag[i])
				{
					que.push(i);
					flag[i] = true;
				}
			}
		}
	}
	printf("%d\n",dis[n]);
}

int main()
{
	int N,T;
	while (~scanf("%d%d",&T,&N))
	{
		int u,v,w;
		for (int i = 1;i <= N;i++)
		{
			for (int j = 1;j <= i;j++)
			{
				if (i == j) edge[i][j] = 0;
				else edge [i][j] = edge[j][i] = INF;
			}
		}
		for (int i = 0;i < T;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			/*if (w < edge[u][v])
			{
				edge[u][v] = edge[v][u] = w;
			}*/
			edge[u][v] = edge[v][u] = min(w,edge[u][v]);
		}
		spfa(N);
	}
	return 0;
}

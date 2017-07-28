#include<cstdio>
#include<queue>
using namespace std; 
#define INF 0x3f3f3f3f
const int MAX_N = 105;
bool flag[MAX_N];
int edge[MAX_N][MAX_N];

int spfa(int n)
{
	int dis[MAX_N];
	queue<int >que;
	
	for (int i = 1;i <= n;i++)
	{
		dis[i] = INF;
		flag[i] = false;
	} 
	
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
			if (dis[curval] < dis[i] - edge[curval][i]) //dis[i] > dis[curval} + edge[curval][i]
			{
				dis[i] = dis[curval] + edge[curval][i];
				if (!flag[curval])
				{
					que.push(i);
					flag[i] = true;
				}
			}
		}
	}
	return dis[n];
}

int main()
{
	int n,m,u,v,val;
	
	while (~scanf("%d%d",&n,&m) != EOF && n && m)
	{
		for (int i= 1;i <= n;i++)
		{
			for (int j = 1;j <= i;j++)
			{
				if (i == j) edge[i][j] = 0;
				else edge[i][j] = edge[j][i] = INF;
			}
		}
		
		for (int i = 0;i < m;i++)
		{
			scanf("%d%d%d",&u,&v,&val);
			edge[u][v] = edge[v][u] = val;
		}
		
		int time = spfa(n);
		
		printf("%d\n",time);
	}
	return 0;
}

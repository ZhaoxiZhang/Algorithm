#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1005;
int dis[maxn][maxn];

int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{
		int s,x1,y1,x2,y2,u,v,d;
		memset(dis,0x3f,sizeof(dis));
		for (int i = 0;i <= n;i++)
		{
			dis[i][i] = 0;
		}
		scanf("%d%d%d%d%d",&s,&x1,&y1,&x2,&y2);
		while (m--)
		{
			scanf("%d%d%d",&u,&v,&d);
			dis[u][v] = d;
		}
		for (int k = 0;k <= n;k++)
		{
			for (int i= 0;i <= n;i++)
			{
				for (int j = 0;j <= n;j++)
				{
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		int res = dis[s][x1] + dis[x1][y1] + dis[y1][x2] + dis[x2][y2];
		res = min(res,dis[s][x1] + dis[x1][x2] + dis[x2][y1] + dis[y1][y2]);
		res = min(res,dis[s][x1] + dis[x1][x2] + dis[x2][y2] + dis[y2][y1]);
		res = min(res,dis[s][x2] + dis[x2][y2] + dis[y2][x1] + dis[x1][y1]);
		res = min(res,dis[s][x2] + dis[x2][x1] + dis[x1][y2] + dis[y2][y1]);
		res = min(res,dis[s][x2] + dis[x2][x1] + dis[x1][y1] + dis[y1][y2]);
		printf("%d\n",res);
	}
	return 0;
} 

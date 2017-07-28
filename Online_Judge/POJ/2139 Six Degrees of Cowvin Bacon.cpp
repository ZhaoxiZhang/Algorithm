#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


const int INF = 0x3f3f3f3f;
int dis[305][305];

void floyd(int n)
{
	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}



int main()
{
	int N,M;
	memset(dis,0x3f,sizeof(dis));
	while (~scanf("%d%d",&N,&M))
	{
		int ans[305];
		int tmp;
		while (M--)
		{
			scanf("%d",&tmp);
			for (int i = 0;i < tmp;i++)
			{
				scanf("%d",&ans[i]);
			}
			for (int i = 0;i < tmp;i++)
			{
				for (int j = 0;j < i;j++)
				{
					dis[ans[i]][ans[j]] = dis[ans[j]][ans[i]] = 1;
				}
			}
		}
		floyd(N);
		int res = 0x3f3f3f3f;
		for (int i = 1;i <= N;i++)
		{
			int sum = 0;
			for (int j = 1;j <= N;j++)
			{
				if (i != j)
					sum += dis[i][j];
			}
			res = min(res,sum);
		}
		printf("%d\n",100*res/(N-1));
	}
	return 0;
}


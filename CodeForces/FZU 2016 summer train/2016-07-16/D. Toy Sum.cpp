#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 10000000;
int vis[1000005];

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		memset(vis,0,sizeof(vis));
		int tmp,cnt = 0;
		bool first = true;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&tmp);
			vis[tmp] = 1;
		}
		printf("%d\n",N);
		for (int i = 1;i <= maxn;i++)
		{
			if (vis[i] && !vis[maxn+1-i])
			{
				first?printf("%d",maxn+1-i):printf(" %d",maxn+1-i);
				first = false;
				cnt++;
			}
		}
		for (int i = 1;i <= maxn && cnt != N;i++)
		{
			if (!vis[i] && !vis[maxn+1-i])
			{
				printf(" %d %d",i,maxn+1-i);
				cnt += 2;
			}
		}
		printf("\n");
	}
	return 0;
}

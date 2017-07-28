#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int x,i,j,cnt;
		bool vis[1005];
		memset(vis,false,sizeof(vis));
		for (i = 0;i < N;i++)
		{
			scanf("%d",&x);
			for (j = 0,cnt = 0;cnt <= x;j++)
			{
				if (!vis[j+1])
				{
					cnt++;
				}
			}
			if (i)
			{
				printf(" ");
			}
			printf("%d",j);
			vis[j] = true;
		}
		printf("\n");
	}
	return 0;
} 

/*
5
2 0 1 0 0

3 1 4 2 5
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int M,tmp;
		int ans[105][105] = {0};
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&M);
			for (int j = 0;j < M;j++)
			{
				scanf("%d",&tmp);
				ans[i][tmp-1] = 1;
			}
		}
		for (int i = 0;i < N;i++)
		{
			int j ,k;
			bool flag = false;
			for (j = 0;j < N;j++)
			{
				if (i == j) continue;
				for (k = 0;k < 100;k++)
				{
					if (ans[i][k] == 0 && ans[j][k] == 1)
					{
						break;
					}
				}
				if (k == 100)
				{
					flag = true;
				}
			} 
			if (!flag)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	} 
	return 0;
}

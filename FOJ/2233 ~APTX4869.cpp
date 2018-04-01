#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	
	while (scanf("%d",&n) != EOF)
	{
		int i,j,k,tmp;
		int ans[805][805];
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < n;j++)
			{
				scanf("%d",&ans[i][j]);
			}
		}
		int max = 0;
		for (i = 0;i < n - 1;i++)
		{
			for (j = i + 1;j < n;j++)
			{
				for (k = i + 1;k < n - 1 -j;k++)
				{
					if (ans[i][k] > ans[i][k + 1])
					{
						tmp = ans[i][k];
						ans[i][k] = ans[i][k + 1];
						ans[i][k + 1] = tmp;
					}
				} 
			}
			if (max < ans[i][0])
			{
				max = ans[i][0];
			}
		}
		printf("%d\n",max);
	}
	return 0;
} 

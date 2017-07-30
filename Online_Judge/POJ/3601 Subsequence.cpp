#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,S,i;
		int ans[100005] = {0},sum[100005] = {0};
		scanf("%d%d",&N,&S);
		int res = N;
		for (i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
			sum[i + 1] = sum[i] + ans[i];
		}
		if (sum[i] < S)
		{
			res = 0;
		}
		else
		{
			for (i = 0;sum[i] + S < sum[N];i++)
			{
				int tmp = lower_bound(sum + i,sum + N,sum[i] + S) - sum;
				res = min(res,tmp - i);
			}
		}
		printf("%d\n",res);
	}
	return 0;
} 

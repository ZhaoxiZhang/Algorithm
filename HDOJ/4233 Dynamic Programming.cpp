#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int main()
{
	int T,Case = 0;
	scanf("%d",&T);
	while (T--)
	{
		int N,tmp,sum[maxn] = {0};
		scanf("%d",&N);
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&tmp);
			sum[i] = sum[i-1] + tmp; 
		}
		sort(sum,sum+N+1);
		int res = sum[1]-sum[0];
		for (int i = 0;i < N;i++)
		{
			res = min(res,sum[i+1]-sum[i]);
		}
		printf("Case %d: %d\n",++Case,res);
	}
	return 0;
}

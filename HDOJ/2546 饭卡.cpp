#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	while (~scanf("%d",&n) && n)
	{
		int a[1005] = {0},dp[1005] = {0};
		for (int i = 0;i < n;i++)	scanf("%d",&a[i]);
		scanf("%d",&m);
		if (m - 5 < 0)	printf("%d\n",m);
		else
		{
			sort(a,a+n);
			for (int i = 0;i < n - 1;i++)
			{
				for (int j = m - 5;j >= a[i];j--)
				{
					dp[j] = max(dp[j],dp[j-a[i]]+a[i]); 
				}
			}
			printf("%d\n",m - a[n-1] - dp[m-5]);
		}
	}
	return 0;
}

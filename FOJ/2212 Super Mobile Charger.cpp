#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,M;
		int ans[105];
		scanf("%d%d",&N,&M);
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
			ans[i] = 100 - ans[i];
		}
		sort(ans,ans + N);
		int cnt = 0;
		for (int i =0 ;i < N;i++)
		{
			M -= ans[i];
			if (M < 0)
			{
				break;
			}
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
} 

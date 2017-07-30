#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const LL INF = 0x3f3f3f3f;
LL ans[100005];
LL N,K;

bool OK(LL x)
{
	LL sum = 0;
	for (int i = 0;i < N;i++)
	{
		sum += min(x,ans[i]);
	}
	return sum >= K;
}

int main()
{
	while (~scanf("%I64d%I64d",&N,&K))
	{
		LL sum = 0;
		vector<LL>itv;
		vector<LL>::iterator it;
		memset(ans,0,sizeof(ans));
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d",&ans[i]);
			sum += ans[i];
		}
		
		if (K > sum)
		{
			printf("-1\n");
			continue;
		}
		
		LL left = 0,right = INF;
		while (left < right - 1)
		{
			LL mid = left + ((right-left) >> 1);
			if (OK(mid))
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}
		LL val = left;
		for (int i = 0;i < N;i++)
		{
			K -= min(ans[i],val);
			ans[i] -= min(ans[i],val);
		}
		for (int i = 0;i < N;i++)
		{
			if (K && ans[i])
			{
				ans[i]--;
				K--;
			}
			else if (!K && ans[i])
			{
				itv.push_back(i+1);
				ans[i] = 0;
			} 
		}
		for (int i = 0;i < N;i++)
		{
			if (ans[i])
			{
				itv.push_back(i+1);
			}
		}
		bool first = true;
		for (it = itv.begin();it != itv.end();it++)
		{
			first?printf("%I64d",*it):printf(" %I64d",*it);
			first = false;
		}
		printf("\n");
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;

int main()
{
	LL N,X;
	while (~scanf("%I64d%I64d",&N,&X))
	{
		LL ans[100005] = {0};
		LL sum = 0;
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d",&ans[i]);
		}
		sort(ans,ans+N);
		for (int i = 0;i < N;i++)
		{
			if (X > 1)
			{
				sum += ans[i]*X;
				X--;
			}
			else if (X == 1)
			{
				sum += ans[i];
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}


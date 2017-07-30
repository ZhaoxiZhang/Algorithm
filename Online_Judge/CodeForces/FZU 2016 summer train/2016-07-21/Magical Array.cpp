#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 LL;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		LL ans[100005] = {0};
		LL res = N,cnt = 1;
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d",&ans[i]);
		}
		for (int i = 0;i < N - 1;i++)
		{
			if(ans[i] == ans[i+1])
			{
				cnt++;
			}
			else
			{
				res += cnt*(cnt - 1)/2;
				cnt = 1; 
			}
		}
		if (cnt != 1)
		{
			res += (cnt - 1)*cnt/2;
		} 
		printf("%I64d\n",res);
	}
	return 0;
} 

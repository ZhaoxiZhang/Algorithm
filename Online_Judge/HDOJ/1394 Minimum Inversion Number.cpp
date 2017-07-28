#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int ans[5005] = {0};
		int sum = 0,res;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
		}
		for (int i = 0;i < N;i++)
		{
			for (int j = i + 1;j < N;j++)
			{
				if (ans[i] > ans[j])
				{
					sum++;
				}
			}
		}
		res = sum;
		for (int i = 0;i < N;i++)
		{
			sum += N - ans[i] - ans[i] - 1;
			res = min(res,sum);
		}
		printf("%d\n",res);
	}
	return 0;
}

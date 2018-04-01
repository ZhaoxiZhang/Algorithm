#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const int maxn =  10005;

int main()
{
	int N;
	while (~scanf("%d",&N) && N)
	{
		int ans[maxn] = {0};
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
		}
		int max,sum = 0,left = 0,right = 0,tmp = 0;
		for (int i = 0;i < N;i++)
		{
			sum += ans[i];
			if (i == 0)
			{
				max = sum;
			}
			if (sum > max)
			{
				max = sum;
				right = i;
				left = tmp;
			}
			if (sum < 0)
			{
				sum = 0;
				tmp = i + 1;
				
			}
		}
		if (max < 0)
		{
			max = 0;
			left = 0;
			right = N - 1;
		}
		printf("%d %d %d\n",max,ans[left],ans[right]);
	}
	return 0;
}

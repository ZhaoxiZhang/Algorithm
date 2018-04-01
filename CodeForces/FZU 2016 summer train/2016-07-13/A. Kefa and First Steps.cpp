#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	int ans[100005] = {0};
	scanf("%d",&N);
	for (int i = 0;i < N;i++)
	{
		scanf("%d",&ans[i]);
	}
	__int64 sum = 0;
	__int64 max = 0;
	for (int i =0;i < N - 1;i++)
	{
		if (ans[i+1] >= ans[i])
		{
			++sum;
			if (sum > max)
			{
				max = sum;
			}
		}
		else
		{
			sum = 0;
		}
	}
	printf("%I64d\n",max+1);
	return 0;
}

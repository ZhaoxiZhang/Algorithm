#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 LL; 


int main()
{
	int K;
	while (~scanf("%d",&K) && K)
	{
		LL tmp,left,right,sum = -0xffffffff,max = -0xffffffff;
		for (int i = 0;i < K;i++)
		{
			scanf("%I64d",&tmp);
			if (sum < 0)
			{
				sum = tmp;
				left = tmp; 
			}
			else
			{
				sum += tmp;
			}
			if (sum > max)
			{
				max = sum;
				right = tmp;
			}
		}
		if (max < 0)
		{
			printf("0,%I64d %I64d\n",left,right);
		}
		else
		{
			printf("%I64d %I64d %I64d\n",max,left,right);
		}
	}
	return 0;
}

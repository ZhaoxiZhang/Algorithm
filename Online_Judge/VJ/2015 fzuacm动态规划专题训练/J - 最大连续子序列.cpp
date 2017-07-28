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
		LL sum[10005] = {0};
		LL str[10005] = {0};
		LL left,right,res;
		for (int i = 1;i <= K;i++)
		{
			scanf("%I64d",&str[i]);
			sum[i] = sum[i-1] + str[i];
		}
		res = str[1];
		for (int i = 1;i <= K;i++)
		{
			for (int j = i;j <= K;j++)
			{
				if (res < sum[j] - sum[i-1])
				{
					res = sum[j] - sum[i-1];
					left = str[i];
					right = str[j];
				}
			}
		}
		if (res >= 0)
		{
			printf("%I64d %I64d %I64d\n",res,left,right);
		}
		else
		{
			printf("0 %I64d %I64d\n",str[1],str[K]);
		}
		
	}
	return 0;
}

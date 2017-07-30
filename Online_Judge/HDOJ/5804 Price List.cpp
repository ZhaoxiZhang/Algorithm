#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		__int64 N,M,tmp;
		scanf("%I64d%I64d",&N,&M);
		__int64 valsum = 0;
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d",&tmp);
			valsum += tmp;
		}
		while (M--)
		{
			scanf("%I64d",&tmp);
			if (tmp > valsum)	printf("1");
			else	printf("0");
		}
		printf("\n");
	}
	return 0;
}

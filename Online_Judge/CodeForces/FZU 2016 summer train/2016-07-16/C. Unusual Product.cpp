#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const int MAX = 1005;
int ans[MAX][MAX];

int main()
{
	int N,q,sum = 0;
	memset(ans,0,sizeof(ans));
	scanf("%d",&N);
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			scanf("%d",&ans[i][j]);
		}
	}
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			sum += ans[i][j]*ans[j][i];
		}
	}
	sum %= 2;
	scanf("%d",&q);
	while (q--)
	{
		int opt,tmp;
		scanf("%d",&opt);
		if (opt != 3)
		{
			scanf("%d",&tmp);
			if (sum == 0) sum = 1;
			else if (sum == 1) sum = 0;
		}
		else
		{
			printf("%d",sum);
		}
	}
	printf("\n");
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		//int ans[1005];
		int sum = 0,N,tmp;
		scanf("%d",&N);
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&tmp);
			sum += tmp;
		}
		printf("%d\n",sum + N);
	}
	return 0;
}

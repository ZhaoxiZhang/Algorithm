#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int itv[10005];
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&itv[i]);
		}
		sort(itv,itv+N);
		printf("%d\n",itv[N/2]);
	}
	return 0;
} 

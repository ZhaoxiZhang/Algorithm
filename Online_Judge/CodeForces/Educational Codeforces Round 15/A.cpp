#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int ans[100005] = {0};
		int maxx = 0,res = 0;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
		}
		for (int i = 1;i < N;i++)
		{
			if (ans[i] > ans[i-1])
			{
				res++;
			}
			else
			{
				res = 0;
			}
			maxx = max(maxx,res);
		}
		printf("%d\n",maxx+1);
	}
	return 0;
}


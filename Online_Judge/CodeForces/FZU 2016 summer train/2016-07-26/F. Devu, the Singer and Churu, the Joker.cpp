#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
	int N,D;
	while (~scanf("%d%d",&N,&D))
	{
		int ans[105] = {0};
		int sum = 0;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
			sum += ans[i];
		}
		if ((sum + 10*(N - 1)) > D)
		{
			printf("-1\n");
		}
		else
		{
			int maxx,res,cnt;
			maxx = sum + (N - 1)*10;
			cnt = 2*(N - 1);
			res = D - maxx;
			cnt += res/5;
			printf("%d\n",cnt);
		}
	}
	return 0;
}


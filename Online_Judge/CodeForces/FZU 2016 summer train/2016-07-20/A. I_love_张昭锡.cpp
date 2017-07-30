#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int N,cnt = 0;
	int ans[1005] = {0};
	int maxx,minn;
	scanf("%d",&N);
	scanf("%d",&ans[0]);
	maxx = minn = ans[0];
	for (int i = 1;i < N;i++)
	{
		scanf("%d",&ans[i]);
		if (ans[i] > maxx)
		{
			cnt++;
			maxx = ans[i];
		}
		if (ans[i] < minn)
		{
			cnt++;
			minn = ans[i];
		}
	}
	printf("%d\n",cnt);
	return 0;
} 

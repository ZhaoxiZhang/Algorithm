#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
const int MAX_N = 105;
pair<int,int>itv[MAX_N];

int main()
{
	int N;
	while(~scanf("%d",&N) && N)
	{
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&itv[i].second,&itv[i].first);
		}
		sort(itv,itv+N);
		int t = 0,cnt = 0;
		for (int i = 0;i < N;i++)
		{
			if (t <= itv[i].second)
			{
				cnt++;
				t = itv[i].first;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

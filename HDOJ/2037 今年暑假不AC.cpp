#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d",&n) && n)
	{
		pair<int ,int >itv[105];
		for (int i = 0;i < n;i++)
		{
			scanf("%d%d",&itv[i].second,&itv[i].first);
		}
		
		sort(itv,itv + n);
		
		int sum = 0,t = 0;
		for (int i = 0;i < n;i++)
		{
			if (t <= itv[i].second)
			{
				sum++;
				t = itv[i].first;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

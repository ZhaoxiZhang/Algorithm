#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	int ans[105];
	scanf("%d",&N);
	for (int i = 0;i < N;i++)
	{
		scanf("%d",&ans[i]);
	}
	sort(ans,ans+N);
	for (int i = 0;i < N;i++)
	{
		i == 0?printf("%d",ans[i]):printf(" %d",ans[i]);
	}
	return 0;
}

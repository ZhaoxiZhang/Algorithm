#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int ans[1000001];
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&ans[i]);
		}
		sort(ans,ans + n);
		printf("%d",ans[n - 1]);
		for(int i = n - 2;m > 1;m--,i--)
		{
			printf(" %d",ans[i]);
		} 
		printf("\n");
	}
	return 0;
} 

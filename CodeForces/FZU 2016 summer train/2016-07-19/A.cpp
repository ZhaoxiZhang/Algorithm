#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int N,sum,res = 0x3f3f3f3f;
	int ans[200005];
	char str[200005];
	bool flag = false;
	memset(ans,0,sizeof(ans));
	memset(str,0,sizeof(str));
	scanf("%d",&N);
	getchar();
	for (int i = 0;i < N;i++)
	{
		scanf("%c",&str[i]);
	}
	for (int i = 0;i < N;i++)
	{
		scanf("%d",&ans[i]);
	}
	for (int i = 0;i < N - 1;i++)
	{
		if (str[i] == 'R')
		{
			if (str[i+1] == 'L')
			{
				flag = true;
				sum = (ans[i+1] - ans[i])/2;
				res = min(sum,res);
			}
		}
	}
	if (!flag)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",res);
	}
	return 0;
}

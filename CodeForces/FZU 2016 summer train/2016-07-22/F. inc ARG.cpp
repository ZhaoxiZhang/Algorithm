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
		char ans[105];
		int a[105]= {1},b[105] = {0},c[105];
		int cnt = 0;
		memset(ans,0,sizeof(ans));
		getchar();
		for (int i = 0;i < N;i++)
		{
			scanf("%c",&ans[i]);
		}
		for (int i = 0;i < N;i++)
		{
			c[i] = b[i] = ans[i] - '0';
		}
		for (int i = 0;i < N;i++)
		{
			b[i] += a[i];
			b[i+1] += b[i]/2;
			b[i] %= 2;
		}
		for (int i = 0;i < N;i++)
		{
			if(c[i] != b[i])
			{
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}


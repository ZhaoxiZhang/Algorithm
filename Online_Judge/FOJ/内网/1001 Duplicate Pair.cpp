#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int ans[1000000];
int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		memset(ans,0,sizeof(ans));
		int res,tmp;
		bool flag = false;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&tmp);
			if (flag)
			{
				continue;
			} 
			if (!ans[tmp])
			{
				ans[tmp] = 1;
			}
			else
			{
				res = tmp;
				flag = true;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

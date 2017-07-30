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
		int ans[1005] = {0};
		int tmp,cnt = 0,res = 1;
		for (int i = 0; i < N;i++)
		{
			scanf("%d",&tmp);
			if (tmp == 1)
			{
				ans[cnt++] = i;
			}
		}
		if (cnt == 0)
		{
			printf("0\n");
			continue;
		}
		for (int i = 0;i < cnt - 1;i++)
		{
			if (ans[i+1] - ans[i] >= 2)
			{
				res += 2;
			}
			else if (ans[i+1] - ans[i] == 1)
			{
				res++;
			} 
		}
		printf("%d\n",res);
	}
	return 0;
} 

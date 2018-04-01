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
		int res,res1 = 0,res2 = 0,maxx = 0,minn = 0x3f3f3f3f,sign = -1;
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&ans[i]);
			sign *= sign;
			res += ans[i]*sign;
			maxx = max(maxx,res);
			minn = min(minn,res);
		}
		res1 = 0;
		res2 = 0;
		int s1 = ans[0];
		for (int i = 1;i <= N;i++)
		{
			sign *= sign;
			res1 += ans[i]*sign;
			res2 += ans[i];
			for (int j = s1;j <= res2;j++)
			{
				if (res1 >= 0)
				{
					for(int j = 0;j < res1;j++)
					{
						printf("\n");
					}
				}
				else if(res1 < 0)
				{
					for (int j = 0;j < maxx;j++)
					{
						printf("\n");
					}
					for(int j = 0;j >= res1;j--)
					{
						printf("\n");
					}
				}
				for (int k = 0;k < res2;k++)
				{
					if(k)	printf(" ");
				}
				if (i & 1)
				{
					printf("/");
				}
				else
				{
					printf("\\");
				}
				s1++; 
			}
			s1 = res2;
		}
	}
	return 0;
}

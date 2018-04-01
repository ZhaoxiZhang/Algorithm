#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int x,int y)
{
	return x>y;
}


int main()
{
	int N;
	while (~scanf("%d",&N) && N)
	{
		int ans[10005] = {0};
		bool flag = true;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
		}
		while (flag)
		{
			sort(ans,ans+N,cmp);
			int tmp = ans[0];
			if (tmp == 0)
			{
				break;
			}
			for (int i = 1;i <= tmp;i++)
			{
				ans[i]--;
				if (ans[i] < 0)
				{
					flag = false;
					break;
				}
			}
			ans[0] = 0;
			if (!flag)
			{
				break;
			}
		}
		if (!flag)
		{
			printf("Not possible\n");
		}
		else
		{
			printf("Possible\n");
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;


int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int ans[10005] = {0};
		int x,res = 0,minn,pos;
		while (N--)
		{
			bool flag = false;
			minn = INF;
			scanf("%d",&x);
			for (int i = 0;i < res;i++)
			{
				if (x < ans[i] && minn > ans[i] - x)
				{
					minn = ans[i] - x;
					pos = i;
					flag = true;
				} 
			}
			if (!flag)
			{
				ans[res++] = x;
			}
			else
			{
				ans[pos] = x;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}


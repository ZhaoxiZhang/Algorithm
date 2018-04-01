#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
	int p,q,r,l;
	while (~scanf("%d%d%d%d",&p,&q,&l,&r))
	{
		int a[1005],b[1005];
		int x,y,res = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		while (p--)
		{
			scanf("%d%d",&x,&y);
			for (int i = x;i <= y;i++)
			{
				a[i] = 1;
			}
		}
		while (q--)
		{
			scanf("%d%d",&x,&y);
			for (int i = x;i <= y;i++)
			{
				b[i] = 1;
			}
		}
		for (int i = l;i <= r;i++)
		{
			for (int j = i;j <= 1000;j++)
			{
				if(b[j-i] && a[j])
				{
					res++;
					break;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
} 

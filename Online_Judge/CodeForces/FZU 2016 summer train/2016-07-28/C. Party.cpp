#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,res = 0;
int father[2005];

void init()
{
	for (int i = 0;i <= N;i++)
	{
		father[i] = i;
	}
}

void unite(int x,int y)
{
	father[x] = y;
	return;
}

void find(int x)
{
	if (x == father[x])
		return;
	res++;
	find(father[x]);
}

int main()
{
	while (~scanf("%d",&N))
	{
		int tmp,maxx = 0;
		init();
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&tmp);
			if (tmp != -1)
			{
				unite(i,tmp);
			}
		}
		for (int i = 1;i <= N;i++)
		{
			res = 1;
			find(i);
			maxx = max(res,maxx);
		}
		printf("%d\n",maxx);
	}
	return 0;
}


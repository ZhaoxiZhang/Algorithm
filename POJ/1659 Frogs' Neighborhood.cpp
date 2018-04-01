#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
	int val,id;
};

bool cmp(Node x,Node y)
{
	return x.val > y.val;
}



int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		Node xi[15];
		int map[15][15];
		int N;
		bool success = true,first;
		memset(xi,0,sizeof(xi));
		memset(map,0,sizeof(map));
		scanf("%d",&N);
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&xi[i].val);
			xi[i].id = i;
		}
		while (true)
		{
			sort(xi+1,xi+N+1,cmp);
			if (xi[1].val == 0)
			{
				break;
			}
			int tmp = xi[1].val;
			for (int i = 2;i <= tmp+1;i++)
			{
				xi[i].val--;
				if (xi[i].val < 0)
				{
					success = false;
					break;
				}
				map[xi[1].id][xi[i].id] = map[xi[i].id][xi[1].id] = 1;
			}
			xi[1].val = 0;
			if (!success)
			{
				break;
			}
		}
		if (!success)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for (int i = 1;i <= N;i++)
			{
				first = true;
				for (int j = 1;j <= N;j++)
				{
					first?printf("%d",map[i][j]):printf(" %d",map[i][j]);
					first = false;
				}
				printf("\n");
			}
		}
		if (T != 0)
		{
			printf("\n");
		}
	}
}

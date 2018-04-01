#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;


struct Node{
	LL val,id;
};

Node peo[100005],clo[100005];

int main()
{
	LL n,m,x,y;
	while (~scanf("%I64d%I64d%I64d%I64d",&n,&m,&x,&y))
	{
		LL cnt = 0;
		memset(peo,0,sizeof(peo));
		memset(clo,0,sizeof(clo));
		for (int i = 1;i <= n;i++)
		{
			scanf("%I64d",&peo[i].val);
			peo[i].id = i;
		}
		for (int i = 1;i <= m;i++)
		{
			scanf("%I64d",&clo[i].val);
			clo[i].id = i;
		}
		int j = 1;
		for (int i = 1;i <= m;i++)
		{
			while (j <= n )
			{
				if (clo[i].val < peo[j].val - x)
				{
					break;
				}
				else if (clo[i].val >= peo[j].val - x && clo[i].val <= peo[j].val + y)
				{
					cnt++;
					j++;
					break;
				}
				else 
				{
					j++;
				}
			}
		}
		printf("%I64d\n",cnt);
		j = 1;
		for (int i = 1;i <= m;i++)
		{
			while (j <= n)
			{
				if (clo[i].val < peo[j].val - x)
				{
					break;
				}
				else if (clo[i].val >= peo[j].val - x && clo[i].val <= peo[j].val + y)
				{
					printf("%I64d %I64d\n",peo[j].id,clo[i].id);
					j++;
					break;
				}
				else
				{
					j++;
				}
			}
		}
	}
	return 0;
}


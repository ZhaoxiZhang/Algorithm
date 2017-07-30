#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
struct node{
	LL money,fac;
}; 
node p[100005];
LL sum[100005];
bool cmp(node x,node y)
{
	if (x.money == y.money)
		return x.fac > y.fac;
	else
		return x.money < y.money;
}

int main()
{
	int n,d;
	while (~scanf("%d%d",&n,&d))
	{
		LL res = 0;
		memset(p,0,sizeof(p));
		memset(sum,0,sizeof(sum));
		for (int i = 0;i < n;i++)
		{
			scanf("%I64d%I64d",&p[i].money,&p[i].fac);
		}
		sort(p,p+n,cmp);
		for (int i = 0;i < n;i++)
		{
			sum[i+1] = sum[i] + p[i].fac;
		}
		int i= 0,j = 1;
		while (i < n)
		{
			while (j < n && p[j].money -p[i].money < d)
			{
				j++;
			}
			res = max(res,sum[j] - sum[i]);
			i++;
		}
		printf("%I64d\n",res);
	}
	return 0;
}


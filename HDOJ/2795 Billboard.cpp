#include<cstdio>
#include<iostream>
using namespace std;
#define lson l , m ,rt << 1
#define rson m + 1 ,r , rt << 1 | 1
const int maxn = 200005;
int MAX[maxn<<2];
int h,w,n;

void PushUp(int rt)
{
	MAX[rt] = max(MAX[rt<<1],MAX[rt<<1|1]);
}

void build(int l,int r,int rt)
{
	MAX[rt] = w;
	if (l == r)	return;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}

int qry(int x,int l,int r,int rt)
{
	if (l == r)
	{
		MAX[rt] -= x;
		return l;
	}
	int m = (l + r) >> 1;
	int ret = (MAX[rt<<1] >= x)?qry(x,lson):qry(x,rson);
	PushUp(rt);
	return ret;
}

int main()
{
	while (~scanf("%d%d%d",&h,&w,&n))
	{
		int x;
		if (h > n)
		{
			h = n;
		}
		build(1,h,1);
		while (n--)
		{
			scanf("%d",&x);
			if (MAX[1] < x)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n",qry(x,1,h,1));
			}
		} 
	}
	return 0;
}


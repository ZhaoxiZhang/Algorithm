#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt << 1
#define rson m+1,r,rt << 1 | 1
const int maxn = 200005;
int maxv[maxn << 2];

void PushUp(int rt)
{
	maxv[rt] = max(maxv[rt << 1],maxv[rt << 1 | 1]);
} 

void build(int l,int r,int rt)
{
	if (l == r)
	{
		scanf("%d",&maxv[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}

void upd (int p,int val,int l,int r,int rt)
{
	if (l == r)
	{
		maxv[rt] = val;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) upd(p,val,lson);
	else upd(p,val,rson);
	PushUp(rt);
}

int qry(int L,int R,int l,int r,int rt)
{
	if (L <= l && r <= R)
	{
		return maxv[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret = max(ret,qry(L,R,lson));
	if (R > m) ret = max(ret,qry(L,R,rson));
	return ret;
}

int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		char opt;
		int x,y;
		memset(maxv,0,sizeof(maxv));
		build (1,N,1);
		while (M--)
		{
			getchar();
			scanf("%c %d %d",&opt,&x,&y);
			if (opt == 'Q')
			{
				printf("%d\n",qry(x,y,1,N,1));
			}
			if (opt == 'U')
			{
				upd(x,y,1,N,1);
			}
		}
	}
	return 0;
} 

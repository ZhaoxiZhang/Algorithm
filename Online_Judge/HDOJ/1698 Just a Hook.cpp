#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l ,m ,rt << 1
#define rson m + 1 ,r , rt << 1 | 1
const int maxn = 100005;
int sum[maxn<<2],col[maxn<<2];

void PushUp(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown(int rt,int m)
{
	if (col[rt])
	{
		col[rt<<1] = col[rt<<1|1] = col[rt];
		sum[rt<<1] = (m - (m >> 1)) * col[rt];
		sum[rt<<1|1] = (m >> 1) * col[rt];
		col[rt] = 0;
	}
}

void build(int l,int r,int rt)
{
	col[rt] = 0;
	sum[rt] = 1;
	if (l == r)	return;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}

void upd(int L,int R,int c,int l,int r,int rt)
{
	if (L <= l && r <= R)
	{
		col[rt] = c;
		sum[rt] = (r - l + 1) * c;
		return;
	}
	PushDown(rt,r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m)	upd(L,R,c,lson);
	if (R > m)	upd(L,R,c,rson);
	PushUp(rt);
}


int main()
{
	int T;
	scanf("%d",&T);
	for (int i =1;i <= T;i++)
	{
		int n,m,x,y,z;
		scanf("%d%d",&n,&m);
		build(1,n,1);
		while (m--)
		{
			scanf("%d%d%d",&x,&y,&z);
			upd(x,y,z,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",i,sum[1]); 
	}
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1, r , rt << 1 | 1
const int maxn = 5005;
int sum[maxn<<2];

void PushUp(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
} 

void build(int l,int r,int rt)
{
	sum[rt] = 0;
	if (l == r)	return;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}


void upd(int p,int l,int r,int rt)
{
	if (l == r)
	{
		sum[rt]++;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m)	upd(p,lson);
	else	upd(p,rson);
	PushUp(rt);
}

int qry(int L,int R,int l,int r,int rt)
{
	if (L <= l && r <= R)
	{
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m)	ret += qry(L,R,lson);
	if (R > m)	ret += qry(L,R,rson);
	return ret;
}

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int ans[maxn];
		build(0,N - 1,1);
		int sum = 0;
		for (int i = 0; i < N;i++)
		{
			scanf("%d",&ans[i]);
			sum += qry(ans[i],N - 1,0,N - 1,1);
			upd(ans[i],0,N - 1,1); 
		}
		int ret = sum;
		for (int i = 0;i < N;i++)
		{
			sum += N - ans[i] - ans[i] - 1;
			ret = min(ret,sum);
		}
		printf("%d\n",ret);
	}
	return 0;
}

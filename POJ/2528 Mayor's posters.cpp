#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 11111;
bool hash[maxn];
int li[maxn],ri[maxn],ans[maxn<<2],lazy[maxn<<4];
int res;

void PushDown(int rt)
{
	if (lazy[rt] != -1)
	{
		lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
		lazy[rt] = -1;
	}
}

void upd(int L,int R,int c,int l,int r,int rt)
{
	if (L <= l && r <= R)
	{
		lazy[rt] = c;
		return;
	}
	PushDown(rt);
	int m = (l + r)>>1;
	if (L <= m)	upd(L,R,c,lson);
	if (m < R)	upd(L,R,c,rson);
}

void qry(int l,int r,int rt)
{
	if (lazy[rt] != -1)
	{
		if (!hash[lazy[rt]])	res++;
		hash[lazy[rt]] = true;
		return ;
	}
	if (l == r)	return;
	int m = (l + r) >> 1;
	qry(lson);
	qry(rson);
}

int binary(int key,int n,int a[])
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (a[m] == key)	return m;
		if (a[m] < key)	l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--)
	{
		memset(lazy,-1,sizeof(lazy));
		memset(hash,false,sizeof(hash));
		scanf("%d",&n);
		int cnt = 0;
		for (int i = 0;i < n;i++)
		{
			scanf("%d%d",&li[i],&ri[i]);
			ans[cnt++] = li[i];
			ans[cnt++] = ri[i];
		}
		sort(ans,ans+cnt);
		cnt = unique(ans,ans + cnt) - ans;
		for (int i = cnt - 1;i > 0;i--)
		{
			if (ans[i] != ans[i-1] + 1)
			{
				ans[cnt++] = ans[i - 1] + 1;
			}
		}
		sort(ans,ans + cnt);
		for (int i = 0;i < n;i++)
		{
			int l = lower_bound(ans,ans + cnt,li[i]) - ans;
			int r = lower_bound(ans,ans + cnt,ri[i]) - ans;
			upd(l,r,i,0,cnt,1);
		}
		res = 0;
		qry(0,cnt,1);
		printf("%d\n",res);
	}
	return 0;
}

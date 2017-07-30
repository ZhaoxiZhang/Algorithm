#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 200005;
int a[maxn],cnt[maxn];

bool cmp(int x,int y)
{
	return x >= y;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int n,q,l,r;
	LL res = 0;
	memset(cnt,0,sizeof(cnt));
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)	scanf("%d",&a[i]);
	while (q--)
	{
		scanf("%d%d",&l,&r);
		cnt[l]++;
		cnt[r+1]--;
	}
	for (int i = 1;i <= n;i++)	cnt[i] += cnt[i-1];
	sort(a+1,a+n+1);
	sort(cnt+1,cnt+n+1);
	for (int i = n;i > 0;i--)
	{
		res += LL(a[i])*(LL)cnt[i];
	}
	printf("%I64d\n",res);
	return 0;
}

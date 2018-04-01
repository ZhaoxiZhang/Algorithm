#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn],b[maxn],dpa[maxn],dpb[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(dpa, 0, sizeof(dpa));
    	memset(dpb, 0, sizeof(dpb));
		int m,n,res = 0,maxa = 0,maxb = 0,minn;
		scanf("%d%d",&n,&m);
		for (int i = 0;i < n;i++)	scanf("%d",&a[i]),maxa = maxa>a[i]?maxa:a[i];
		for (int i = 0;i < m;i++)	scanf("%d",&b[i]),maxb = maxb>b[i]?maxb:b[i];
		dpa[a[0]] = 1,dpb[b[0]] = 1;
		for (int i = 1;i < n;i++)	dpa[a[i]] = dpa[a[i] - 1] + 1;
		for (int i = 1;i < m;i++)	dpb[b[i]] = dpb[b[i] - 1] + 1;
		minn = maxa<maxb?maxa:maxb;
		for (int i = 1;i <= minn;i++)	res = max(res,min(dpa[i],dpb[i]));
		printf("%d\n",res);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int fa[maxn],a[maxn];
bool vis[maxn];

int find(int x)
{
	return fa[x] == x ? fa[x] : find(fa[x]);
}

void unite(int x,int y)
{
	int fx = find(x),fy = find(y);
	if (fx == fy)	return;
	fa[fy] = fx;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int n,m,k,empty = 0,res = 0;
	scanf("%d%d",&n,&m);
	for (int i = 0;i <= m;i++)	fa[i] = i,vis[i] = false;
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&k);
		if (!k)
		{
			empty++;
			continue;
		}
		scanf("%d",&a[0]);
		vis[a[0]] = true;
		for (int i = 1;i < k;i++)
		{
			scanf("%d",&a[i]);
			vis[a[i]] = true;
			unite(a[i],a[i-1]);
		}		
	}
	for (int i = 1;i <= m;i++)
	{
		if (vis[i] && find(i) == i)	res++;
	}
	if (res)	printf("%d\n",res - 1 + empty);
	else	printf("%d\n",empty);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;
LL sum[maxn],ans[maxn];
int fa[maxn],pos[maxn];
bool vis[maxn]; 

void init(int n)
{
	memset(vis,false,sizeof(vis));
	for (int i = 0;i <= n;i++)	fa[i] = i;
}

int find(int x)
{
	return x == fa[x]?fa[x]:find(fa[x]);
}

void Union(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)	return;
	fa[fx] = fy;
	sum[fy] += sum[fx];
}

int main()
{
	int n;
	LL tmp = 0;
	scanf("%d",&n);
	init(n);
	for (int i = 1;i <= n;i++)	scanf("%I64d",&sum[i]);
	for (int i = 1;i <= n;i++)	scanf("%d",&pos[i]);
	for (int i = n; i > 0;i--)
	{
		ans[i] = tmp;
		vis[pos[i]] = true;
		if (pos[i] < n && vis[pos[i] + 1])	Union(pos[i],pos[i]+1);
		if (pos[i] > 1 && vis[pos[i] - 1])	Union(pos[i],pos[i]-1);
		tmp = max(tmp,sum[find(pos[i])]);
	}
	for (int i = 1;i <= n;i++)	printf("%I64d\n",ans[i]);
	return 0; 
}

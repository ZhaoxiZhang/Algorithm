#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int init[maxn],goal[maxn];
vector<int>ans,itv[maxn];

void dfs(int u,int fa,int odd,int even)
{
	if (odd)	init[u] ^= 1;
	if (init[u] != goal[u])
	{
		odd ^= 1;
		ans.push_back(u);
	}
	int size = itv[u].size();
	for (int i = 0;i < size;i++)
	{
		int v = itv[u][i];
		if (fa == v)	continue;
		dfs(v,u,even,odd);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	int n,u,v;
	scanf("%d",&n);
	for (int i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		itv[u].push_back(v);
		itv[v].push_back(u);
	}
	for (int i = 1;i <= n;i++)	scanf("%d",&init[i]);
	for (int i = 1;i <= n;i++)	scanf("%d",&goal[i]);
	dfs(1,1,0,0);
	int size = ans.size();
	printf("%d\n",size);
	for (int i = 0;i < size;i++)	printf("%d\n",ans[i]);
	return 0;
	
}

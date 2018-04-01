#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 100005;
vector<int>itv[maxn];
int maxx,scc_cnt,index,top,dfn[maxn],low[maxn],st[maxn],inst[maxn];

void init()
{
	maxx = top = scc_cnt = index = 0;
	memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));
	memset(st,0,sizeof(st));memset(inst,0,sizeof(inst));
}

void targin(int u)
{
	int v;
	dfn[u] = low[u] = ++index;
	st[++top] = u;
	inst[u] = 1;
	for (int i = 0;i < itv[u].size();i++)
	{
		v = itv[u][i];
		if (!dfn[v])
		{
			targin(v);
			low[u] = min(low[u],low[v]);
		}
		else if (inst[v])
		{
			low[u] = min(low[u],dfn[v]);
		}
	}
	if (dfn[u] == low[u])
	{
		scc_cnt++;
		do
		{
			v = st[top--];
			inst[v] = 0;
		}
		while (u != v);
	}
}

int main()
{
	int p1,p2;
	init();
	while (~scanf("%d%d",&p1,&p2) && p1 != -1 && p2 != -1)
	{
		if (p1 || p2)
		{
			itv[p1].push_back(p2);
			itv[p2].push_back(p1);
			maxx = max(maxx,max(p1,p2));
			continue;
		}
		for (int i = 1;i <= maxx;i++)	if (!dfn[i])	targin(i);
		printf("%d\n",scc_cnt);
		if (scc_cnt != 0)	printf("No\n");
		else	printf("Yes\n");
		init();
	}
	return 0;
} 


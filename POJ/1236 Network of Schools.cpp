#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 105;
struct Edge{
	int v,next;
}edge[maxn*maxn];
int head[maxn],dfn[maxn],low[maxn],st[maxn],inst[maxn],belong[maxn],indeg[maxn],outdeg[maxn];
int tot,top,in,out,scc_cnt,index,N;

void init()
{
	tot = top = scc_cnt = index = 0;
	in = out = 0;
	memset(head,-1,sizeof(head));	memset(inst,0,sizeof(inst));
	memset(dfn,0,sizeof(dfn));		memset(low,0,sizeof(low));
	memset(indeg,0,sizeof(indeg));	memset(outdeg,0,sizeof(outdeg));
}

void addedge(int u,int v)
{
	edge[tot] = (Edge){v,head[u]};
	head[u] = tot++;
}

void targin(int u)
{
	int v;
	dfn[u] = low[u] = ++index;
	st[++top] = u;
	inst[u] = 1;
	for (int i = head[u];i != -1;i = edge[i].next)
	{
		v = edge[i].v;
		if (!dfn[v])
		{
			targin(v);
			low[u] = min(low[u],low[v]);
		}
		else if (inst[v])
			low[u] = min(low[u],dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		scc_cnt++;
		do
		{
			v = st[top--];
			inst[v] = 0;
			belong[v] = scc_cnt;
		}
		while (u != v);
	}
}

int main()
{
	while (~scanf("%d",&N))
	{
		int v;
		init();
		for (int i = 1;i <= N;i++)
			while (~scanf("%d",&v) && v)	addedge(i,v);
		for (int i = 1;i <= N;i++)	if (!dfn[i])	targin(i);
		for (int i = 1;i <= N;i++)
		for (int j = head[i]; j != -1;j = edge[j].next)
		{
			v = edge[j].v;
			if (belong[i] != belong[v])
			{
				indeg[belong[v]]++;
				outdeg[belong[i]]++;
			}
		}
		for (int i = 1;i <= scc_cnt;i++)
		{
			if (!indeg[i])	in++;
			if (!outdeg[i])	out++;
		}
		if (scc_cnt == 1)	printf("1\n0\n");
		else printf("%d\n%d\n",in,max(in,out)); 
	}
	return 0;
}

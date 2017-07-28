#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 10005;
struct Edge{
	int to,next;
}edge[maxn];
vector<int>qry[maxn];
int N,tot,fa[maxn],head[maxn],indegree[maxn],ancestor[maxn];
bool vis[maxn];

void init()
{
	tot = 0;
	for (int i = 1;i <= N;i++)	fa[i] = i,head[i] = -1,indegree[i] = 0,vis[i] = false,qry[i].clear();
}

void addedge(int u,int to)
{
	edge[tot] = (Edge){to,head[u]};
	head[u] = tot++; 
}

int find(int x)
{
	int r = x;
	while (r != fa[r])	r = fa[r];
	int i = x,j;
	while (i != r)
	{
		j = fa[i];
		fa[i] = r;
		i = j;
	}
	return r;
}

void Union(int x,int y)
{
	x = find(x),y = find(y);
	if (x == y)	return;
	fa[y] = x;	//不能写成fa[x] = y,与集合合并的祖先有关系 
}

void targin_LCA(int u)
{
	ancestor[u] = u;
	for (int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		targin_LCA(v);
		Union(u,v);
		ancestor[find(u)] = u;
	}
	vis[u] = true;
	int size = qry[u].size();
	for (int i = 0;i < size;i++)
	{
		if (vis[qry[u][i]])	printf("%d\n",ancestor[find(qry[u][i])]);
		return;
	}
} 

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int u,v;
		scanf("%d",&N);
		init();
		for (int i = 1;i < N;i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			indegree[v]++;
		}
		scanf("%d%d",&u,&v);
		qry[u].push_back(v),qry[v].push_back(u);
		for (int i = 1;i <= N;i++)
		{
			if (!indegree[i])
			{
				targin_LCA(i);
				break;
			}
		}
	}
	return 0;
}

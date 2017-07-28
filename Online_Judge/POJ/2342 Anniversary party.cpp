/*
	dp[x][0]:x 不去参加聚会
	dp[x][1]:x 去参加聚会
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn =  6005;
int tot = 0,fa[maxn],head[maxn],dp[maxn][2];;
struct Tree{
	int fa,son;
	int next;
	Tree():fa(0),son(0),next(0){}
}tree[maxn];

void addedge(int u,int v)
{
	tree[tot].son = v;
	tree[tot].next = head[u];
	head[u] = tot++;
}

void dfs(int cur)
{
	for (int i = head[cur];i != -1;i = tree[i].next)
	{
		dfs(tree[i].son);
		dp[cur][1] += dp[tree[i].son][0];
		dp[cur][0] += max(dp[tree[i].son][0],dp[tree[i].son][1]);
	}
}


int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		memset(head,-1,sizeof(head));
		memset(dp,0,sizeof(dp));
		for (int i = 1;i <= N;i++)	scanf("%d",&dp[i][1]);
		int L,K;
		while (scanf("%d%d",&L,&K) && L && K)
		{
			tree[L].fa = K;
			addedge(K,L);
		}
		int root = 1;
		while (tree[root].fa)	root = tree[root].fa;
		dfs(root);
		printf("%d\n",max(dp[root][0],dp[root][1]));
	}
	return 0;
}

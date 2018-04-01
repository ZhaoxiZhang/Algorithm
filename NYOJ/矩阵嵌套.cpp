#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1005;
struct Node{
	int len,wid;
}node[maxn];
int dp[maxn],edge[maxn][maxn];

bool cmp(struct Node x,struct Node y)
{
	if (x.len == y.len)	return x.wid < y.wid;
	else	return x.len < y.len;
} 

void addedge(int N)
{
	for (int i = 0;i < N;i++)
	{
		for (int j = i + 1;j < N;j++)
		{
			if (node[i].len < node[j].len && node[i].wid < node[j].wid)	edge[i][j] = 1;
		}
	}
}

int solve(int i,int N)
{
	int &ans = dp[i];
	if (ans > 0)	return ans;
	ans = 1;
	for (int j = 0;j < N;j++)	if (edge[i][j])	ans = max(ans,solve(j,N) + 1);
	return ans;
}

int main()
{
	int T,N,x,y;
	scanf("%d",&T);
	while (T--)
	{
		int tmp,res = 0;
		memset(dp,0,sizeof(dp));
		memset(edge,0,sizeof(edge));
		scanf("%d",&N);
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&x,&y);
			node[i].len = x>y?x:y;
			node[i].wid = x<y?x:y;
		}
		sort(node,node+N,cmp);
		addedge(N);
		for (int i = 0;i < N;i++)
		{
			tmp = solve(i,N);
			res = tmp>res?tmp:res;
		}
		printf("%d\n",res);
	}
	return 0;
}

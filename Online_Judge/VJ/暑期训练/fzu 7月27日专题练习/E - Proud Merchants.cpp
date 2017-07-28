#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
	int p,q,v;
};

bool cmp(Node x,Node y)
{
	return (x.q - x.p) < (y.q - y.p);
}


int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		Node node[505];
		int dp[5005];
		memset(dp,0,sizeof(dp));
		memset(node,0,sizeof(node));
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d%d",&node[i].p,&node[i].q,&node[i].v);
		}
		sort(node,node+N,cmp);
		for(int i = 0;i < N;i++)
		{
			for (int j = M;j >= node[i].q;j--)
			{
				dp[j] = max(dp[j-node[i].p] + node[i].v,dp[j]);
			}
		}
		printf("%d\n",dp[M]);
	}
	return 0;
}

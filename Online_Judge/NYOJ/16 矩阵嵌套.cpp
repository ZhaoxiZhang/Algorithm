#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1005;
struct Node{
	int len,wid;
}node[maxn];

bool cmp(struct Node xx,struct Node yy)
{
	if (xx.len == yy.len)	return xx.wid < yy.wid;
	else	return xx.len < yy.len;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,l,w,res = 0;
		int dp[maxn] = {0};
		scanf("%d",&N);
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&l,&w);
			node[i].len = l > w?l:w;
			node[i].wid = w < l?w:l;
		}
		sort(node,node+N,cmp);
		for (int i = 0;i < N;i++)
		{
			dp[i] = 1;
			for (int j = 0;j < i;j++)
			{
				if (node[i].wid > node[j].wid && node[i].len > node[j].len && dp[j] + 1 > dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}
			res = max(res,dp[i]);
		}
		printf("%d\n",res);	
	}
	return 0;
}

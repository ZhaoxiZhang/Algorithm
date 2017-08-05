#include<bits/stdc++.h>
using namespace std;
const int maxn =  2005;
vector<int>itv[maxn];
int res = 0;

void dfs(int u,int depth)
{
	res = max(res,depth);
	for (unsigned i = 0;i < itv[u].size();i++)
	{
		dfs(itv[u][i],depth + 1);
	}
}

int main()
{
	int n,p;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&p);
		if (p == -1)	itv[0].push_back(i);
		else	itv[p].push_back(i);
	}
	dfs(0,0);
	printf("%d\n",res);
	return 0;
}

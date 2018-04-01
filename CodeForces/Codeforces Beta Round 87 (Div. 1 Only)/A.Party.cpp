#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
vector<int>itv[maxn];
int level[maxn];

int main()
{
	int n,p;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&p);
		if (~p)	itv[p].push_back(i);
		else	itv[0].push_back(i);
	}
	queue<int>que;
	for (unsigned i = 0;i < itv[0].size();i++)
	{
		int u = itv[0][i];
		que.push(u);
		level[u] = 1;
		while (!que.empty())
		{
			u = que.front();
			que.pop();
			for (unsigned j = 0;j < itv[u].size();j++)
			{
				int v = itv[u][j];
				level[v] = level[u] + 1;
				que.push(v);
			}
		}
	}
	int res = 1;
	for (int i = 1;i <= n;i++)	res = max(res,level[i]);
	printf("%d\n",res);
	return 0;
}

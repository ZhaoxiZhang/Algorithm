#include<bits/stdc++.h>
using namespace std;
const int maxn = (1<<16)+5;
int deg[maxn],sum[maxn];

int main()
{
	int n;
	queue<int>que;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d%d",&deg[i],&sum[i]);
		if (deg[i] == 1)	que.push(i);
	}
	vector<pair<int,int> >ans;
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		if (deg[u] == 0)	continue;
		int v = sum[u];
		ans.push_back(make_pair(u,v));
		deg[v]--,sum[v] ^= u;
		if (deg[v] == 1)	que.push(v);
	}
	int size = ans.size();
	printf("%d\n",size);
	for (int i = 0;i < size;i++)	printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}

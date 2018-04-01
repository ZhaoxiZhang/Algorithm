#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int p[maxn],a[maxn],b[maxn];
bool vis[maxn];
set<pair<int,int> >s[5];

int main()
{
	int n,m,t;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)	scanf("%d",&p[i]);
	for (int i = 0;i < n;i++)	scanf("%d",&a[i]);
	for (int i = 0;i < n;i++)	scanf("%d",&b[i]);
	for (int i = 0;i < n;i++)
	{
		s[a[i]].insert(make_pair(p[i],i));
		s[b[i]].insert(make_pair(p[i],i));
		vis[i] = true;
	}
	scanf("%d",&m);
	while (m--)
	{
		int ans = -1;
		scanf("%d",&t);
		while (!s[t].empty())
		{
			int pos = (*(s[t].begin())).second;
			s[t].erase(s[t].begin());
			if (!vis[pos])	continue;
			ans = p[pos];
			vis[pos] = false;
			break;
		}
		printf("%d ",ans);
	}
	puts(" ");
	return 0;
}

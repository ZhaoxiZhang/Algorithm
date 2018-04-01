#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
set<int>s[maxn];
int a[maxn];

int main()
{
	freopen("input.txt","r",stdin);
	int n,m,u,v,pos = 0;
	unsigned int res = 0;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)	scanf("%d",&a[i]);
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d",&u,&v);
		s[a[u]].insert(a[v]);
		s[a[v]].insert(a[u]);
	}
	//cout << s[2].size() << endl;
	//cout << s[3].size() << endl;
	for (int i = 1;i <= n;i++)
	{
		if (s[a[i]].size() == res && a[i] < pos)
		{
			pos = a[i];
		}
		else if (s[a[i]].size() > res)
		{
			res = s[a[i]].size();
			pos = a[i];
		}
	}
	printf("%d\n",pos);
	return 0;
}

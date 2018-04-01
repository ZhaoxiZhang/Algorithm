#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;
map<int,int>mp;
int a[maxn];

int main()
{
	int n,m,k,tmp,pos;
	LL res = 0;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]] = i;
	}
	for (int i = 0;i < m;i++)
	{
		scanf("%d",&tmp);
		pos = mp[tmp];
		res += (LL)(pos / k + 1);
		if (pos)
		{
			mp[tmp] = pos - 1;
			mp[a[pos-1]] = pos;
			swap(a[pos-1],a[pos]);
		}
	}
	printf("%I64d\n",res);
	return 0;
} 

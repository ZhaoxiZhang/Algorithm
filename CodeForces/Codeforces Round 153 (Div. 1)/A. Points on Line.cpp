#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
typedef __int64 LL;
int a[maxn];

int main()
{
	int n,d,pos;
	LL res = 0,tmp = 0;
	scanf("%d%d",&n,&d);
	for (int i = 0;i < n;i++)	scanf("%d",&a[i]);
	for (int i = n - 3;i >= 0;i--)
	{
		pos = upper_bound(a,a + n,a[i] + d) - a;
		tmp = pos - i - 1;
		if (tmp - 1 > 0)	res += tmp*(tmp-1)/2;
	}
	printf("%I64d\n",res);
	return 0;
} 

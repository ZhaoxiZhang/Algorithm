#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];

int main()
{
	int n,L;
	bool first = false,last = false;
	scanf("%d%d",&n,&L);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i] == 0)	first = true;
		if (a[i] == L)	last = true;
	}
	if (!first)	a[n++] = 0;
	if (!last)	a[n++] = L;
	sort(a,a + n);
	int res = 0;
	for (int i = 1;i < n;i++)
	{
		res = max(res,a[i]-a[i-1]);
	}
	if (!first)	res = max(res,a[1]*2);
	if (!last)	res = max(res,(a[n-1] - a[n-2])*2);
	printf("%.10lf\n",(double)res/2);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 500005;
int a[maxn],cnt[maxn];

int main()
{
	int n;
	LL res = 0,sum = 0;
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if (sum % 3)
	{
		printf("0\n");
	}
	else
	{
		sum /= 3;
		LL ss = 0;
		for (int i = n - 1;i >= 0;i--)
		{
			ss += a[i];
			if (ss == sum)	cnt[i]++;
		}
		for (int i = n - 2;i >= 0;i--)	cnt[i] += cnt[i+1];
		ss = 0;
		for (int i = 0;i < n - 2;i++)
		{
			ss += a[i];
			if (ss == sum)	res += (LL)cnt[i+2];
		}
		printf("%I64d\n",res);
	}
	return 0;
}

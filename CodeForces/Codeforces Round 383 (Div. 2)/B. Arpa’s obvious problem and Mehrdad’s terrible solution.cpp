#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn],cnt[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	int n,x;
	scanf("%d%d",&n,&x);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	__int64 res = 0;
	for (int i = 0;i < n;i++)
	{
		if (cnt[(a[i]^x)] > 0)
		{
			if ((x^a[i]) == a[i])	res += cnt[a[i]]-1;	
			else	res += cnt[(a[i]^x)];
		}
	}
	printf("%I64d\n",res/2);
	return 0;
}

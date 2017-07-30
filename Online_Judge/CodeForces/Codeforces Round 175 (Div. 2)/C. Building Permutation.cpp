#include<bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int a[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)	scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	__int64 res = 0;
	for (int i = 1;i <= n;i++)
	{
		res += (__int64)abs(i-a[i]);
	}
	printf("%I64d\n",res);
	return 0;
} 

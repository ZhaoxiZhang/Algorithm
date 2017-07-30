#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int mod = 1e9+7;
const int maxn = 1000005;
char str[maxn];
LL a[maxn];

int main()
{
	LL res = 0;
	scanf("%s",str);
	int len = strlen(str);
	if (str[len - 1] == 'b')	a[len-1] = 1; 
	for (int i = len - 2;i >= 0;i--)
	{
		if (str[i] == 'a' && str[i+1] == 'b')
		{
			res = (res%mod + a[i+1]%mod)%mod;
			a[i] = (2*a[i+1])%mod;
			str[i] = 'b';
		}
		else if ((str[i] == 'b' && str[i+1] == 'a') || (str[i] == 'b' && str[i+1] == 'b'))
		{
			a[i] = (a[i+1] +1)%mod;
		}
		else if (str[i] == 'a' && str[i+1] == 'a')
		{
			a[i] = a[i+1]; 
		}
	}
	printf("%I64d\n",res);
	return 0;
}

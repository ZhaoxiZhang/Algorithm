#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;

int main()
{
	LL n,a,b,c,tmp;
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
	LL cnt = 0;
	LL d = b - c;
	if (d < a && n >= b)
	{
		n -= b;
		tmp = n / d;
		cnt += tmp;
		n -= tmp*d;
		LL dif = n + b;
		while (dif >= b)
		{
			tmp = dif/b;
			cnt += tmp;
			dif -= tmp*b;
			dif += tmp*c;
		}
		cnt += dif/a;
	}
	else
	{
		tmp = n/a;
		cnt += tmp;
		n -= tmp*a;
		LL dif = n;
		while (dif >= b)
		{
			tmp = dif/b;
			cnt += tmp;
			dif -= tmp*b;
			dif += tmp*c;
		}
	}
	printf("%I64d\n",cnt);
	return 0;
}

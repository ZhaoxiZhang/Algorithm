#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

__int64 gcd(__int64 a,__int64 b)
{
	return b?gcd(b,a%b):a;
}

void extgcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
	}
	else
	{
		extgcd(b,a%b,y,x);
		y -= x*(a/b);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		__int64 n,B,a,b,c,t,g,k1,k2;
		scanf("%I64d%I64d",&n,&B);
		a = B;
		b = -9973;
		c = n;
		g = gcd(a,b);
		a /= g;
		b /= g;
		c /= g;
		extgcd(a,b,k1,k2);
		t = -c*k1/b;
		k1 = c*k1+t*b;
		if (k1 < 0)
		{
			k1 += b;
		}
		printf("%I64d\n",k1%9973);
	}
	return 0;
} 

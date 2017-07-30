#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
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
	int k,Ktmp;
	while (~scanf("%d",&k))
	{
		Ktmp = k;
		vector<__int64>ai,ri;
		__int64 tmp1,tmp2,min,val;
		bool flag = false;
		while (k--)
		{
			scanf("%I64d%I64d",&tmp1,&tmp2);
			ai.push_back(tmp1);
			ri.push_back(tmp2);
		}
		for (int i = 0;i < Ktmp;i++)
		{
			__int64 a,b,c,g,t,k1,k2;
			a = ai[i];
			b = -ai[i+1];
			c = ri[i+1] - ri[i];
			g = gcd(a,b);
			if (c % g == 0)
			{
				flag = true;
				a /= g;
				b /= g;
				c /= g;
				extgcd(a,b,k1,k2);
				t = -c*k1/b;
				k1 = c*k1+b*t;
				if (k1 < 0)
				{
					k1 += b;
				}
				val = ai[i]*k1+ri[i];
			}
			if (i == 0)
			{
				min = val;
			}
			else
			{
				if (min > k1)
				{
					min = val;
				}
			}
		}
		if (!flag)
		{
			printf("-1\n");
		}
		else
		{
			printf("%I64d\n",min);
		}
	}
	return 0;
} 

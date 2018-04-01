#include<iostream>
#include<algorithm>
#include<cstdio>

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
	__int64 x,y,m,n,L;
	while (~scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L))
	{
		__int64 a,b,c,g,k1,k2,t;
		a = n-m;
		b = L;
		c = x - y;
		g = gcd(a,b);
		if (c % g)
		{
			printf("Impossible\n");
		}
		else
		{
			a /= g;
			b /= g;
			c /= g;
			extgcd(a,b,k1,k2);
			t = -c*k1/b;
			k1 = c*k1+t*b; //注释 
			if (k1 < 0)
			{
				k1 += b;
			}
			printf("%I64d\n",k1);
		}
	}
	return 0;
}


/*注 1：此时方程的所有解为：x=c*k1:+b*t,x的最小的可能值是0，
令x=0可求出当x最小时的t的取值，但由于x=0是可能的最小取值，
实际上可能x根本取不到0，那么由计算机的取整除法可知：
由 t=-c*k1/b算出的t，代回x=c*k1+b*t中，求出的x可能会小于0，
此时令t=t+1，求出的x必大于0；如果代回后x仍是大于等于0的，
那么不需要再做修正。*/

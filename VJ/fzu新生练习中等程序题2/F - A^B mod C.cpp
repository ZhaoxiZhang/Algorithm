#include<stdio.h>
typedef __int64 LL;


LL mod_mulit(LL x, LL y,LL mod)
{
	LL res = 0;
	while (y)
	{
		if (y & 1)
		{
			res += x;
			while (res >= mod)
			{
				res -= mod;
			}
			//res = (res + x) % mod;  //取模运算耗费时间 
		}
		x += x;
		while (x >= mod)
		{
			x -= mod;
		}
		//x = (x + x) % mod;
		y >>= 1;
	}
	return res;
}

LL mod_pow(LL x,LL n,LL mod)
{
	LL res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res = mod_mulit(res, x, mod);
		}
		x = mod_mulit(x,x,mod);
		n >>= 1;
	}
	return res;
}

int main()
{
	LL A,B,C;
	while (~scanf("%I64d %I64d %I64d",&A,&B,&C))
	{
		/*LL res = 1;
		while (B > 0)
		{
			if (B & 1)
			{
				res = mod_mulit(res,A,C);
			}
			A = mod_mulit(A,A,C);
			B >>= 1;
		}*/
		LL sum = mod_pow(A,B,C);
		printf("%I64d\n",sum);
	}
	return 0;
}


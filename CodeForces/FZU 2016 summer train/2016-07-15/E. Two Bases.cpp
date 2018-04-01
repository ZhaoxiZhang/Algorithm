#include<iostream>
#include<cstdio>
using namespace std;
typedef __int64 LL;

LL pow(LL x,LL n)
{
	LL res = 1;
	while (n>0)
	{
		if (n&1)
		{
			res = res*x;
		}
		x = x*x;
		n >>= 1;
	}
	return res;
}


int main()
{
	LL n,bx,m,by,sumx = 0,sumy = 0;
	LL ansx[100] = {0},ansy[100] = {0};
	scanf("%I64d%I64d",&n,&bx);
	for (int i = n - 1;i >= 0;i--)
	{
		scanf("%I64d",&ansx[i]);
	}
	scanf("%I64d%I64d",&m,&by);
	for (int i = m - 1;i >= 0;i--)
	{
		scanf("%I64d",&ansy[i]);
	}
	for (int i = 0;i < n;i++)
	{
		sumx += ansx[i]*pow(bx,i);
	}
	for (int i = 0;i < m;i++)
	{
		sumy += ansy[i]*pow(by,i);
	}
	if (sumx == sumy)
	{
		printf("=\n");
	}
	else if (sumx < sumy)
	{
		printf("<\n");
	}
	else if (sumx > sumy)
	{
		printf(">\n");
	}
	return 0;
}

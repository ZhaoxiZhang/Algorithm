#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,m,a;
	scanf("%d%d",&n,&m);
	if (m == 1 && n == 1)
	{
		a = 1;
	}
	else if (n&1)
	{
		if (m >= n/2 + 1)
		{
			a = m - 1;
		}
		else if (m < n/2 + 1)
		{
			a = m + 1;
		}
	}
	else
	{
		if (m > n/2)
		{
			a = m - 1;
		} 
		else if (m <= n/2)
		{
			a = m + 1;
		}
	}
	printf("%d\n",a);
	return 0;
}

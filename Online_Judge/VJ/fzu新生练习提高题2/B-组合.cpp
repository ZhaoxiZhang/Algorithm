#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,m,p;
		int pro1 = 1,pro2 = 1;
		scanf("%d%d%d",&n,&m,&p);
		for (int i = n;i >= n - m + 1;i--)
		{
			pro1 *= i;
			pro1 %= p;
		}
		for (int i = 1;i <= m;i++)
		{
			pro2 *= i;
			pro2 %= p;
		}
		printf("%d\n",pro1/pro2);
	}
	return 0;
} 

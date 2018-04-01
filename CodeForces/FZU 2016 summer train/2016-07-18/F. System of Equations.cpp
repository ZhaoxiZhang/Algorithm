#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n,m;
	int res = 0,tmp;
	scanf("%d%d",&n,&m);
	for (int i = 0;i*i <= n;i++)
	{
		tmp = n - i*i;
		if (i+tmp*tmp == m)
		{
			res++;
		}
	}
	printf("%d\n",res);
	return 0;
}

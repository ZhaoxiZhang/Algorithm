#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	while (scanf("%d",&N))
	{
		int a,a1,a2,a3;
		a1 = a2 = 0;
		for (int i =0;i < 3*N-1;i++)
		{
			scanf("%d",&a);
			a2 |= a1&a;
			a1 ^=a;
			a3 = ~(a1&a2);
			a1 &= a3;
			a2 &= a3;
		}
		printf("%010d\n",a2);
	}
	return 0;
}

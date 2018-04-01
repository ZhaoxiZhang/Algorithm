#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a,int b)
{
	return b == 0?a:gcd(b,a%b);
}

int main()
{
	int T,A,B,C;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&A,&C);
		if (C % A == 0)
		{
			B = C/A;
			int tmp = gcd(A,B);
			if (tmp == 1)
			{
				printf("%d\n",C/A);
			}
			else
			{
				int res = 1;
				while (tmp != 1)
				{
					res *= tmp;
					A = A / tmp;
					tmp = gcd(A,B);
				}
				printf("%d\n",res*B);
			}
		}
		else
		{
			printf("NO SOLUTION\n");
		}
	}
	return 0;
}

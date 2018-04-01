#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int pow(int x,int n)
{
	int res = 1;
	while (n)
	{
		if (n&1)	res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

int main()
{
	int N,M,X,K,T;
	int p[15];
	scanf("%d%d",&N,&M);
	for (int i = 0;i < N;i++)	scanf("%d",&p[i]);
	while (M--)
	{
		bool flag = false;
		scanf("%d%d",&X,&K);
		sort(p,p+N);
		do
		{
			T = 0;
			for (int i = 0;i < N;i++)	T += p[i]*pow(10,N-i-1);
			if ((T + X) % K == 0)
			{
				flag = true;
				for (int i = 0;i < N;i++)	printf("%d",p[i]);
				printf("\n");
				break;
			}
		}while (next_permutation(p,p+N));
		if (!flag)	printf("None\n");
	}
	return 0;
} 

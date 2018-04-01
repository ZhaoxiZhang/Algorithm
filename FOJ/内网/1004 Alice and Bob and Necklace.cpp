#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,K;
		scanf("%d%d",&N,&K);
		if (K == 1)
		{
			if (N % 2)
			{
				printf("Alice\n");
			}
			else
			{
				printf("Bob\n");
			}
		}
		else if (K >= N)
		{
			printf("Alice\n");
		}
		else
		{
			printf("Bob\n");
		}
	}
	return 0;
} 

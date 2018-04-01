#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		if (N < 4)
		{
			printf("NO\n");
			continue;
		}
		if (N == 4)
		{
			printf("YES\n");
			printf("1 * 2 = 2\n");
			printf("2 * 3 = 6\n");
			printf("4 * 6 = 24\n");
		} 
		else if (N == 5)
		{
			printf("YES\n");
			printf("5 - 3 = 2\n");
			printf("2 + 1 = 3\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
		}
		else if (N > 5)
		{
			printf("YES\n");
			printf("5 + 1 = 6\n");
			printf("6 - 6 = 0\n");
			for (int i = 7;i <= N;i++)
			{
				printf("0 * %d = 0\n",i);
			}
			printf("2 + 0 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
		}
	}
	return 0;
}


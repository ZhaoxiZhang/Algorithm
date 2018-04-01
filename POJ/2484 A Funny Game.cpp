#include<cstdio>

int main()
{
	int N;
	while (~scanf("%d",&N) && N)
	{
		if (N <= 2)
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


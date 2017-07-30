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
		if (N == 0)
		{
			printf("0\n");
		}
		else if (N > 10 && N < 20)
		{
			printf("4\n");
		}
		else if (N == 20)
		{
			printf("15\n");
		}
		else if (N == 21)
		{
			printf("4\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}

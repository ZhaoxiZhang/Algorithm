#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,m;
	
	while (scanf("%d%d",&n,&m) != EOF &&n && m)
	{
		if (m % 2 == 1 && n % 2 == 1)
		{
			printf("What a pity!\n");
		}
		else
		{
			printf("Wonderful!\n");
		}
	}
	
	return 0;
}

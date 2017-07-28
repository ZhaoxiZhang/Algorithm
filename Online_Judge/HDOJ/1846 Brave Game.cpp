#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int C;
	
	scanf("%d",&C);
	
	while (C--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		
		if (n % (m + 1) == 0)
		{
			printf("second\n");
		}
		else
		{
			printf("first\n");
		}
	}
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if (!(n&1))
	{
		printf("%d\n",n/2 + 1);
		for (int i = 0;i < n/2;i++)	printf("2 ");
		printf("3\n");
	}
	else
	{
		printf("%d\n",n/2);
		printf("2");
		for (int i = 1;i < n/2;i++)	printf(" 2");
		printf("\n");
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		if (i % 4 == 0 || i % 4 == 1)	printf("a");
		else	printf("b");
	}
	printf("\n");
	return 0;
}

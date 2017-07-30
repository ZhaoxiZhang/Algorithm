#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if (n == 0)	printf("1\n");
	else
	{
		n %= 4;
	    if (n == 0)	printf("6\n");
	    if (n == 1)	printf("8\n");
		if (n == 2)	printf("4\n");
		if (n == 3)	printf("2\n");
	}
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if (n == 1)	printf("-1\n");
	else	printf("%d %d %d\n",n*n + n,n + 1,n);
	return 0;
}

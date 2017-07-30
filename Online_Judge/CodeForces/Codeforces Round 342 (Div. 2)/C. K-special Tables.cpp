#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int x = 1,y = n*n - (n - k + 1) * n + 1;
	printf("%d\n",y*n+(n-k+1)*n*(n-1)/2);
	for (int i = 0;i < n;i++)
	{
		for (int u = 0;u < k - 1;u++)	u?printf(" %d",x++):printf("%d",x++);
		for (int u = k - 1;u < n;u++)	u?printf(" %d",y++):printf("%d",y++);
		printf("\n");
		
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
const double PI = acos(-1.0);   
const double e = exp(double(1)); 

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",int(log10(sqrt(2*PI*n))+n*log10(n/e)) + 1);  
	}
	return 0;
}

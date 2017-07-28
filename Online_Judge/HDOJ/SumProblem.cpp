#include<stdio.h>
int main()
{
	int n,i,sum;
	while(~scanf("%d",&n))
	{
		sum=0;
		for(i=0;i<n+1;i++)
		    sum+=i;
		printf("%d\n\n",sum);
	}
    return 0;
}


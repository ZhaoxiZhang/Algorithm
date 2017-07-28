#include<stdio.h>
int main()
{
	int a,b;
	while (scanf("%d%d",&a,&b) != EOF)
	{
		
		if (!a && !b)
			continue;
		else
			printf("%d\n",a + b);
	}
	return 0;
} 

#include<stdio.h>
int main()
{
	int n,i,cnt;
	while (scanf("%d",&n) != EOF)
	{
		cnt = 0;
		for (i = 1;i < n + 1;i++)
		{
			if(n % i == 0) cnt++;
		}
		
		if(cnt%2 == 0)
		{
			printf("0\n");
		} 
		else
		{
			printf("1\n");
		}
	}
	return 0;
}

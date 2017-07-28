#include<stdio.h>

int main()
{
	int N;
	
	while (scanf("%d",&N) != EOF)
	{
		int day = 0;
		
		day = N / 7 * 2;
		
		int tmp = N % 7;
		
		if (tmp != 0)
		{
			if (tmp == 6)
			{
				day += 1;
			}
		}
		printf("%d\n",day);
	}
	
	return 0;
} 

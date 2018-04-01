#include<stdio.h>

int main()
{
	int N,i,count = 0;
	char ans[2005];
	
	scanf("%d",&N);
	
	for (i = 0;i < N;i++)
	{
		getchar();
		scanf("%c",&ans[i]);
	}
	
	int bgn = 0,last = N - 1;
	
	while (bgn <= last)
	{
		bool left = false;
		
		for (i = 0;bgn+i < last + 1;i++)
		{
			if (ans[bgn + i] < ans[last - i])
			{
				left = true;
				break;
			}
			else if(ans[bgn + i] > ans[last - i])
			{
				left = false;
				break;
			}
		}
		
		if (left)
		{
			putchar(ans[bgn++]);
			count++;
		}
		else
		{
			putchar(ans[last--]);
			count++;
		}
		
		if(count % 80 == 0)
		{
			printf("\n");
		}
	}
	return 0;
} 

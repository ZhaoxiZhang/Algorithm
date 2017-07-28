#include<stdio.h>
#include<string.h>

int main()
{
	char ans[100];
	
	
	while (gets(ans))
	{
		int len = strlen(ans);
		for (int i = 0; i < len; i++)
		{
			if ((ans[i] >= 'D' && ans[i] <= 'Z') || (ans[i] >= 'd' && ans[i] <= 'z'))
			{
				printf("%c",ans[i] - 3);
			}
			else if ((ans[i] >= 'A' && ans[i] <= 'C') || (ans[i] >= 'a' && ans[i] <= 'c'))
			{
				printf("%c",ans[i] + 23);
			}
			else
			{
				printf("%c",ans[i]);
			}
		}
		printf("\n");
	}
}

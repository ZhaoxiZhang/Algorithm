#include<stdio.h>
#include<string.h>

int main()
{
	char ans[200];
	ans['A'] = ans['E'] = ans['F']  = 3;
	ans['B'] = ans['D'] = ans['d'] = ans['f']  = 2;
	ans['a'] = ans['b'] = ans['C'] = ans['c'] = ans['e'] = ans['G'] = ans['g'] = 1;
	
	
	int T,i,sum;
	char let[105];
	
	scanf("%d",&T);
	
	while (T--)
	{
		sum = 0;
		scanf("%s",let);
		int len = strlen(let);
		for (i = 0;i < len;i++)
		{
			//scanf("%c",&c);
			sum += ans[let[i]];
		}
		printf("%d\n",sum);
	}	
	return 0;
} 

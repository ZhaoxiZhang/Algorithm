#include<cstdio>
using namespace std;
#define max 30

int main()
{
	char str[max];
	
	while (~scanf("%s",str))
	{
		int a = 0,b = 0,c = 0;
		int i,j;
		for (i = 0,j =1;str[i] != '+';i++,j *= 10)
		{
			a += j*(str[i] - '0');
		}
		for (i = i + 1,j = 1;str[i] != '=';i++,j *= 10)
		{
			b += j*(str[i] - '0');
		}
		for (i = i + 1,j = 1;str[i] != '\0';i++,j *= 10)
		{
			c += j*(str[i] - '0');
		}
		
		if (a + b == c)
		{
			printf("True\n");
			if (!a && !b)
			{
				return 0;
			}
		}
		else
		{
			printf("False\n");
		}
	}
	return 0;
}

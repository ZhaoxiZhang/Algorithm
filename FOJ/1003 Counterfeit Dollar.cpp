#include<string.h>
#include<stdio.h>
using namespace std;
char left[3][10],right[3][10],result[3][5];

bool IsLight(char c)
{
	for (int i = 0;i < 3;i++)
	{
		switch(result[i][0])
		{
			case 'u': if (strchr(right[i],c) == NULL) return false; break;
			case 'd': if (strchr(left[i],c) == NULL) return false; break;
			case 'e': if (strchr(left[i],c) != NULL || strchr(right[i],c) != NULL) return false; break;
		}
	}
	return true;
}

bool IsHeavy(char c)
{
	for (int i = 0;i < 3;i++)
	{
		switch(result[i][0])
		{
			case 'u': if (strchr(left[i],c) == NULL) return false; break;
			case 'd': if (strchr(right[i],c) == NULL) return false; break;
			case 'e': if (strchr(right[i],c) != NULL || strchr(left[i],c) != NULL) return false; break;
		}
	}
	return true;
}

int main()
{
	int N;
	scanf("%d",&N);
	while (N--)
	{
		for (int i = 0;i < 3;i++)
		{
			scanf("%s %s %s",left[i],right[i],result[i]);
		}
		
		for (char c = 'A';c <= 'L';c++)
		{
			if (IsLight(c))
			{
				printf("%c is the counterfeit coin and it is light.\n",c);
				break;
			}
			if (IsHeavy(c))
			{
				printf("%c is the counterfeit coin and it is heavy.\n",c);
				break;
			}
		}	
	}
	return 0;
}

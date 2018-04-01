#include<stdio.h>
#include<string.h>
const int maxn = 100005;

void sign(char *str,int &plus,int &minus)
{
	int i;
	int len = strlen(str);
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '+')	plus = 1,minus = 0;
		if (str[0] == '-')	plus = 0,minus = 1;
		for (i = 0;i < len - 1;i++)
		{
			str[i] = str[i+1];
		}
		str[i] = '\0';
	}
	else
	{
		plus = 1,minus = 0;
	}
}

void cleanfrontzero(char *str)
{
	int zerocnt = 0;
	int len = strlen(str);
	for (int i = 0;str[i] != '.' && i < len;i++)
	{
		if (str[i] != '0')	break;
		if (str[i] == '0')	zerocnt++;
	}
	if (zerocnt)
	{
		for (int i = 0;i < len;i++)
		{
			str[i] = str[i+zerocnt];
		}
	}
}

void cleanbackzero(char *str)
{
	int i; 
	int len = strlen(str);
	if (strstr(str,".") != NULL)
	{
		for (i = len - 1;str[i] == '0';i--)
		{
			str[i] = '\0';
		}
	}
	if (str[i] == '.')	str[i] = '\0';
}

int main()
{
	char str1[maxn],str2[maxn];
	while (~scanf("%s %s",str1,str2))
	{
		int plus1,plus2,minus1,minus2;
		plus1 = plus2 = minus1 = minus2 = 0;
		sign(str1,plus1,minus1);
		sign(str2,plus2,minus2);
		cleanfrontzero(str1);
		cleanbackzero(str1);
		cleanfrontzero(str2);
		cleanbackzero(str2);
		//printf("%s\n%s\n",str1,str2);
		if (strcmp(str1,".") == 0 || strcmp(str1,"") == 0)
		{
			if (strcmp(str1,str2) == 0)	printf("Yes\n");
			else	printf("No\n");
		}
		else
		{
			if (strcmp(str1,str2) == 0 && plus1 == plus2 && minus1 == minus2)	printf("Yes\n");
			else	printf("No\n");
		}
	}
	return 0;
}

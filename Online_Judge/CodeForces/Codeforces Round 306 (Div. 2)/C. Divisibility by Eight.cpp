#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char str[maxn];

void solve()
{
	int len = strlen(str);
	for (int i = 0;i < len;i++)
	{
		int val = str[i] - '0';
		if (val % 8 == 0)
		{
			printf("YES\n");
			printf("%c\n",str[i]);
			return;
		}
	}
	for (int i = 0;i < len;i++)
	{
		for (int j = i + 1;j < len;j++)
		{
			int val = 10*(str[i]-'0') + (str[j]-'0');
			if (val % 8 == 0)
			{
				printf("YES\n");
				printf("%c%c\n",str[i],str[j]);
				return;
			}
		}
	}
	for (int i = 0;i < len;i++)
	{
		for (int j = i + 1;j < len;j++)
		{
			for (int k = j + 1;k < len;k++)
			{
				int val = 100*(str[i]-'0') + 10*(str[j]-'0') + (str[k]-'0');
				if (val % 8 == 0)
				{
					printf("YES\n");
					printf("%c%c%c\n",str[i],str[j],str[k]);
					return;
				} 
			}
		}
	}
	printf("NO\n");
}

int main()
{
	scanf("%s",str);
	solve();
	return 0;
} 

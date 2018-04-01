#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
char str[maxn];

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",str+1);
		int len = strlen(str+1);
		int res = 0;
		for (int i = 1;i <= len && i <= len/4;i++)
		{
			for (int j = 2;i*j*j <= len;j++)
			{
				if (str[i] == 'y' && str[i*j] == 'r' && str[i*j*j] == 'x')	res++;
				if (str[i] == 'x' && str[i*j] == 'r' && str[i*j*j] == 'y')	res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

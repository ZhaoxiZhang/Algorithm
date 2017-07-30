#include<bits/stdc++.h>
using namespace std;
const int maxn = 80005;
char s[maxn];

int pow(int x,int n)
{
	int res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res *= x;
		}
		x *= x;
		n >>= 1;
	}
	return res;
}


int main()
{
	scanf("%s",s);
	int len = strlen(s);
	for (int i = 0;i < len/8;i++)
	{
		int res = 0;
		for (int j = 8*i;j < 8*i+8;j++)
		{
			res += (s[j] - '0')*pow(2,(7-(j-8*i)));
		}
		printf("%c",res);
	} 
	printf("\n");
	return 0;
}

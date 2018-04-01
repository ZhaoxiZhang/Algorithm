#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char a[maxn];
char b[35],tmp[35];

int main()
{
	int cnt = 0;
	scanf("%s %s",a,b);
	int lena = strlen(a);
	int lenb = strlen(b);
	for (int i = 0;i <= lena - lenb;)
	{
		strncpy(tmp,a+i,lenb);
		if (strcmp(tmp,b) == 0)
		{
			cnt++;
			i += lenb;
		}
		else
		{
			i++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

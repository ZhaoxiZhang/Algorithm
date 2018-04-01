#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char s[maxn];

int main()
{
	scanf("%s",s);
	int len = strlen(s);
	for (int i = 0;i < len;i++)
		printf("%c",((s[i]-'a') + 13)%26+'a');
	printf("\n");
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char str[maxn];

int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",str);
	if (a > b)	swap(a,b);
	if (str[a-1] == str[b - 1])	printf("0\n");
	else	printf("1\n");
	return 0;
} 

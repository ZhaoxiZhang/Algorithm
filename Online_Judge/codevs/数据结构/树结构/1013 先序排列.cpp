#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;

void pre(int N,char a[],char b[])
{
	if (N <= 0)	return;
	int pos;
	for (int i = 0;i < N;i++)
		if (a[i] == b[N-1])	pos = i;
	printf("%c",b[N-1]);
	pre(pos,a,b);
	pre(N - pos - 1,a + pos + 1,b + pos);
}


int main()
{
	char a[maxn],b[maxn];
	scanf("%s %s",a,b);
	int len = strlen(a);
	pre(len,a,b);
	return 0;
}

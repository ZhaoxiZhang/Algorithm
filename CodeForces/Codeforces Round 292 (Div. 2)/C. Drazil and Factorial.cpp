#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
char s[maxn];
int a[maxn<<2];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int index = 0,tot = 0;
	while (s[index] == '0') index++;
	for (int i = index;i <= n;i++)
	{
		if (s[i] == '0')	continue;
		if (s[i] == '1')	continue;
		if (s[i] == '2')	a[tot++] = 2;
		if (s[i] == '3')	a[tot++] = 3;
		if (s[i] == '4')	a[tot++] = 3,a[tot++] = 2,a[tot++] = 2;
		if (s[i] == '5')	a[tot++] = 5;
		if (s[i] == '6')	a[tot++] = 5,a[tot++] = 3;
		if (s[i] == '7')	a[tot++] = 7;
		if (s[i] == '8')	a[tot++] = 7,a[tot++] = 2,a[tot++] = 2,a[tot++] = 2;
		if (s[i] == '9')	a[tot++] = 2,a[tot++] = 3,a[tot++] = 3,a[tot++] = 7;
	}
	sort(a,a+tot,cmp);
	for (int i = 0;i < tot;i++)	printf("%d",a[i]);
	printf("\n");
	return 0;	
}

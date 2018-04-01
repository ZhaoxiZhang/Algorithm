#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int main()
{
	//freopen("input.txt","r",stdin);
	int n,a[maxn],b[maxn];
	char astr[maxn],bstr[maxn];
	scanf("%d",&n);
	scanf("%s %s",astr,bstr);
	int len = strlen(astr);
	for (int i = 0;i < len;i++)
	{
		a[i] = astr[i] - '0';
		b[i] = bstr[i] - '0';
	}
	sort(a,a+len);sort(b,b+len);
	int minres = 0,p = len - 1;
	for (int i = len - 1;i >= 0;i--)
	{
		if (a[i] <= b[p])	p--,minres++;
	}
	int maxres = 0;
	p = len - 1;
	for (int i = len - 1;i >= 0;i--)
	{
		if (a[i] < b[p])	p--,maxres++;
	}
	printf("%d\n%d\n",len - minres,maxres);
	return 0;
}

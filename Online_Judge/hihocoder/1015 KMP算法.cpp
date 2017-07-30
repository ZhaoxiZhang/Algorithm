#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
char a[maxn],b[maxn];
int nxt[maxn];

void pre_kmp(char *a,int n)
{
	int i,k;
	for (nxt[0] = k = -1,i = 1;i < n;nxt[i++] = k)
	{
		while (~k && a[k+1] != a[i])	k = nxt[k];
		if (a[k+1] == a[i])	k++;
	}
}

int kmp(char *a,int n,char *b,int m)
{
	int i,k,res = 0;
	for (k = -1,i = 0;i < m;i++)
	{
		while (~k && a[k+1] != b[i])	k = nxt[k];
		if (a[k+1] == b[i])	k++;
		if (k == n - 1)	res++;
	}
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s %s",a,b);
		int alen = strlen(a);
		int blen = strlen(b);
		pre_kmp(a,alen);
		printf("%d\n",kmp(a,alen,b,blen));
	}
	return 0;
}

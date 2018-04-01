#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
//int a[maxn][maxn],b[maxn][maxn],len[maxn];


int main()
{
	freopen("input.txt","r",stdin);
	int n,m,q,l,r;
	scanf("%d%d",&n,&m);
	int **a = (int **)malloc(n*sizeof(int *));
	int **b = (int **)malloc(n*sizeof(int *));
	int *len = (int *)malloc(n*sizeof(int));
	for (int i = 0;i < n;i++)	a[i] = (int *)malloc(m*sizeof(int)),b[i] = (int *)malloc(m*sizeof(int));
	
	for (int i = 0;i < n;i++)	for (int j = 0;j < m;j++)	scanf("%d",&a[i][j]);
		
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			int pos = j;
			int cnt = 0;
			while (pos + 1< n &&a[pos][i] <= a[pos+1][i])	pos++,cnt++;
			for (int k = j;k <= pos;k++)	b[k][i] = pos;
			j += cnt;
		}
	}
	for (int i = 0;i < n;i++)
	{
		len[i] = b[i][0];
		for (int j = 1;j < m;j++)
		{
			len[i] = max(len[i],b[i][j]);
		}
	}
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d",&l,&r);
		if (len[l-1] >= r - 1)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn][maxn],val[maxn];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			scanf("%d",&a[i][j]);
			if (!j)	val[i] = a[i][j];
			else	val[i] = min(val[i],a[i][j]);
		}
	}
	sort(val,val + n);
	printf("%d\n",val[n-1]);
	return 0;
}

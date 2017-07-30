#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;

int main()
{
	int n,k,sum = 0,a[maxn];
	scanf("%d%d",&n,&k);
	for (int i = 0;i < n;i++)	scanf("%d",&a[i]);
	for (int i = 1;i < n;i++)	sum += max(0,k-a[i-1]-a[i]),a[i] +=max(0,k-a[i-1]-a[i]);
	printf("%d\n",sum);
	printf("%d",a[0]);
	for (int i = 1;i < n;i++)	printf(" %d",a[i]);
	printf("\n");
	return 0;
}

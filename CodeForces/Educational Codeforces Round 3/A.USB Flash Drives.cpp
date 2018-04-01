#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 105;
bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	int n,m,res = 0,sum = 0,a[maxn];
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n;i++)	scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	for (int i = 0;i < n;i++)
	{
		res++;
		sum += a[i];
		if (sum >= m)	break;
	}
	printf("%d\n",res);
	return 0;
} 

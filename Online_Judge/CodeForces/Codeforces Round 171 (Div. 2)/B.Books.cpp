#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	int n,t,res = 0;
	scanf("%d%d",&n,&t);
	for (int i = 0;i < n;i++)	scanf("%d",&a[i]);
	int st = 0,ed = 0,sum = 0;
	for (;;)
	{
		if (ed >= n)	break;
		while (ed < n && sum < t)
		{
			sum += a[ed++];
		}
		if (sum > t)	sum -= a[--ed];
		if (ed > n)	break;
		res = max(res,ed - st);
		sum -= a[st++];
	}
	printf("%d\n",res);
	return 0;
}

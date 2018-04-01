#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,a[maxn],cnt[maxn];
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&N);
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		int tmp = cnt[1];
		for (int i = 2;i < maxn;i++)	tmp = gcd(tmp,cnt[i]);
		bool first = true;
		for (int i = tmp;i >= 1;i--)
		{
			if (tmp % i == 0)
			{
				first?printf("%d",N/i):printf(" %d",N/i);
				first = false;
			}
		}
		printf("\n");
	}
	return 0;
}

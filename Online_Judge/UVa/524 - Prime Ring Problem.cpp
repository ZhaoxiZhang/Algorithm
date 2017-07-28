#include<bits/stdc++.h>
using namespace std;
const int maxn = 40;
bool is_prime[maxn],vis[maxn];
int n,a[maxn];

void dfs(int cur)
{
	if (cur == n && is_prime[a[0] + a[n-1]])  //递归边界，因为是环，所以还要测试第一个和最后一个 
	{
		printf("%d",a[0]);
		for (int i = 1;i < n;i++)	printf(" %d",a[i]);
		printf("\n"); 
	}
	else
	{
		for (int i = 2;i <= n;i++)    //尝试放置每个数i 
		{
			if (!vis[i] && is_prime[i + a[cur-1]])  //如果i没有用过，并且与前一个数之和为素数 
			{
				a[cur] = i;
				vis[i] = true;                     //设置使用标志 
				dfs(cur+1);
				vis[i] = false;                    //清楚标志 
			}
		}
	}
}

int main()
{
	//提前预处理素数表 
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2;i < maxn;i++)
	{
		if (is_prime[i])
		{
			for (int j = 2 * i;j < maxn;j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	int tcase = 0;
	while (~scanf("%d",&n))
	{
		memset(vis,false,sizeof(vis));
		memset(a,0,sizeof(a));
		if (tcase)	printf("\n");
		printf("Case %d:\n",++tcase);
		a[0] = 1;
		dfs(1);
	}
	return 0;
} 

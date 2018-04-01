#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		int cnt = 0,pos;
		bool vis[55];
		int prime[55];
		bool is_prime[55];
		memset(prime,0,sizeof(prime));
		memset(is_prime,1,sizeof(is_prime));
		memset(vis,0,sizeof(vis));
		for (int i = 2;i < 55;i++)
		{
			if (!vis[i])
			{
				vis[i] = 1;
				if (is_prime[i])
				{
					prime[cnt++] = i;
					for (int j = 2*i;j < 55;j+= i)
					{
						vis[j] = 1;
						is_prime[j] = 0;
					}
				}
			}
		}
		for (int i = 0;i < 51;i++)
		{
			if (prime[i] == N)
			{
				pos = i;
				break;
			}
		}
		if(prime[pos+1] == M)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	
	return 0;
} 

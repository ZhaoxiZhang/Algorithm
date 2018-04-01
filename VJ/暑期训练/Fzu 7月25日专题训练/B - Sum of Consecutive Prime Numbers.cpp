#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 10005;
int prime[MAX];
bool is_prime[MAX];

int main()
{
	int p = 0;
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2;i <= MAX;i++)
	{
		if (is_prime[i])
		{
			prime[p++] = i;
			for (int j = 2*i;j <= MAX;j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	int N;
	while (~scanf("%d",&N) && N)
	{
		bool flag = false;
		int cnt = 0,s = 0,t = 0,sum = 0;
		for (;;)
		{
			if (prime[t] >= N)	break; 
			while (sum < N)
			{
				sum += prime[t++];
				if (sum == N)
				{
					flag = true;
				}
			}
			if (flag)
			{
				cnt++;
				flag = false;
			}
			sum -= prime[s++];
			if (sum == N && prime[t] < N)
			{
				cnt++;
				sum -= prime[s++];
			}
		}
		if (is_prime[N])printf("%d\n",cnt+1);
		else if (cnt)printf("%d\n",cnt);
		else printf("0\n");
	}
	return 0;
}

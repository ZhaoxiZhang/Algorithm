#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 33000;
bool is_prime[MAX];
int prime[MAX];

int pow(int x,int n)
{
	int res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res *= x;
		}
		x *= x;
		n >>= 1;
	}
	return res;
}

int main()
{
	int x,y,maxx,sum = 1,p = 0;
	int cnt[MAX];
	char ch;
	memset(is_prime,true,sizeof(is_prime));
	memset(prime,0,sizeof(prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2;i <= MAX;i++)
	{
		if (is_prime[i])
		{
			prime[p++] = i;
			for (int j = 2 * i;j <= MAX;j += i)
			{
				is_prime[j] = false;
			}
		}
	} 
	while (1)
	{
		scanf("%d",&x);
		if (x == 0)
			break;
		scanf("%d",&y); 
		sum *= pow(x,y); 
		ch = getchar();
		if (ch == '\n')
		{
			maxx = 0;
			memset(cnt,0,sizeof(cnt));
			sum -= 1;
			int tmpsum = sum;
			for (int i = 0;i < tmpsum;i++)
			{
				while (sum % prime[i] == 0)
				{
					cnt[i]++;
					sum /= prime[i];
					maxx = max(maxx,i);
				}
				if (sum == 0 || sum == 1)
					break;
			}
			bool first = true;
			for (int i = maxx;i >= 0;i--)
			{
				if (cnt[i])
				{
					first?printf("%d %d",prime[i],cnt[i]):printf(" %d %d",prime[i],cnt[i]);
					first = false;
				}
			}
			printf("\n");
			sum = 1;
		}
	}
	return 0;
}

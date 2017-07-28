#include<iostream>
#include<cstdio>
using namespace std;

int pow(int x,int n)
{
	int res = 1;
	while (n>0)
	{
		if (n&1)
		{
			res = res*x;
		}
		x *= x;
		n >>= 1;
	}
	return res;
}


int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int bitset[40] = {0};
		int tmp,res = 0,cnt = 0;
		for (int i = 0;i < 3*N-1;i++)
		{
			scanf("%d",&tmp);
			cnt = 0;
			while (tmp)
			{
				bitset[cnt++] += tmp%2;
				tmp /= 2;
			} 
		}
		for (int i = 0;i < 33;i++)
		{
			if (bitset[i]%3==0)
			{
				bitset[i] = 0;
			}
		}
		for (int i = 0;i < 33;i++)
		{
			if (bitset[i])
			{
				res += pow(2,i);
			}
		}
		printf("%010d\n",res);
	}
	return 0;
} 

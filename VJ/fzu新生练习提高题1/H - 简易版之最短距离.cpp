#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int itv[505];
		int N,tmp;
		int loc,sum = 0;
		scanf("%d",&N);
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&itv[i]);
		}
		sort(itv,itv + N);
		loc  = itv[N/2];
		for (int i = 0;i < N;i++)
		{
			tmp = itv[i] - loc;
			if (tmp < 0)
			{
				sum -= tmp;
			}
			else
			{
				sum += tmp;
			}
		}
		cout << sum << endl;
	}
	return 0;
} 

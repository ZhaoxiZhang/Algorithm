#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int main()
{
	int T;
	int num[] = {6,2,5,5,4,5,6,3,7,6};
	scanf("%d",&T);
	while (T--)
	{
		int N,sum = 0;
		char a[maxn];
		scanf("%d %s",&N,a);
		for (int i = 0;i < N;i++)	sum += num[a[i]-'0'];
		sum -= 2*N;
		for (int i = 0;i < N;i++)
		{
			if (sum >= 4)
			{
				sum -= 4;
				a[i] = '9';
			}
			else if (sum > 0 && sum < 4)
			{
				for (int j = 9;j >= 0;j--)
				{
					if ((num[j] <= sum + 2 && i != N - 1) || num[j] == sum + 2)
					{
						sum -= num[j] - 2;
						a[i] = j + '0';
						break;
					}
				}
			}
			else
			{
				a[i] = '1';
			}
		}
		for (int i = N - 1;i >= 0 && sum > 0;i--)
		{
			a[i] = '8';
			sum--;
		}
		printf("%s\n",a);
	}
	return 0;
}

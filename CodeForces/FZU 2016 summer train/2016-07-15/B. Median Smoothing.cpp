#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans[500005],a[500005];

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int cnt = 2,res = 0,pos;
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
			a[i] = ans[i];
		}
		for (int i = 1;i < N - 1;i++)
		{
			cnt = 2;
			while (ans[i] != ans[i-1] && ans[i] != ans[i+1])
			{
				cnt++;
				i++;
			}
			if (cnt == 2)
				continue;
			if (cnt&1)
			{
				cout << cnt << endl;
				res += cnt / 2;
				pos = i;
				if (ans[i] == 1)
				{
					while (cnt--)
					{
						a[pos--] = 1;
					}
				}
				else if (ans[i] == 0)
				{
					while (cnt--)
					{
						a[pos--] = 0;
					}
				}
			}
			if (!(cnt & 1))
			{
				res += (--cnt)/2;
				pos = i - 1;
				if (ans[i] == 1)
				{
					while (cnt--)
					{
						a[pos] = 0;
					}
				}
				else if (ans[i] == 0)
				{
					while (cnt--)
					{
						a[pos] = 1;
					}
				}
			}
		}
		printf("%d\n",res);
		for (int i = 0;i < N;i++)
		{
			i?printf(" %d",a[i]):printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
} 

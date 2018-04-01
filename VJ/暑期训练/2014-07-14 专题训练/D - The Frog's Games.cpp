#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int ans[500005] = {0};
int L,n,m;
bool C(int d)
{
	int current = 0,cnt = 0;
	for (int i = 0;i <= n;)
	{
		if (ans[i] > current + d || cnt >= m)	return false;
		int pos = upper_bound(ans,ans+n+1,current+d)-ans;
		current = ans[pos-1];
		i = pos;
		cnt++;
	}
	return true;
}



int main()
{
	while (~scanf("%d%d%d",&L,&n,&m))
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&ans[i]);
		}
		ans[n] = L;
		sort(ans,ans+n+1);
		int lb = 0,ub = L,mid;
		while (lb < ub)
		{
			mid = (lb + ub) >> 1;
			if (C(mid))
			{
				ub = mid;
			}
			else
			{
				lb = mid + 1;
			}
		}
		printf("%d\n",lb);
	}
	return 0;
}

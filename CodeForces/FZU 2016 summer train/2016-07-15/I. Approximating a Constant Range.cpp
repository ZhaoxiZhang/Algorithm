#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;

LL abx(LL x)
{
	if (x < 0)
		return -x;
	else
		return x;
}


int main()
{
	LL N;
	LL ans[100005] = {0};
	LL minn,maxx,cnt = 2,res = 2;
	scanf("%I64d",&N);
	for (int i = 0;i < N;i++)
	{
		scanf("%I64d",&ans[i]);
	}
	minn = min(ans[0],ans[1]);
	maxx = max(ans[0],ans[1]);
	
	for (int i = 2;i < N;i++)
	{
		if (abx(ans[i] - maxx) <= 1 && abx(ans[i] - minn) <= 1)
		{
			cnt++;
			maxx = max(ans[i],maxx);
			minn = min(ans[i],minn); 
		}
		else
		{
			cnt = 2;
			minn = min(ans[i],ans[i-1]);
			maxx = max(ans[i],ans[i-1]);
			for (int j = i - 2;j >= 0;j--)
			{
				if (abx(ans[j] - maxx) <= 1 && abx(ans[j] - minn) <= 1)
				{
					cnt++;
					maxx = max(maxx,ans[j]);
					minn = min(minn,ans[j]);
				}
				else
				{
					break;
				}
			}
		}
		if (res < cnt)
		{
			res = cnt;
		}
	}
	printf("%I64d\n",res);
	return 0;
}

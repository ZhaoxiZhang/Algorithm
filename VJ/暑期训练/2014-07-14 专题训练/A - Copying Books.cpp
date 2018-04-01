#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL M,K;
int ans[505];

bool OK(LL x)
{
	LL sum = 0,cnt = 0;
	for (int i = 0;i < M;i++)
	{
		sum += ans[i];
		if (sum > x)
		{
			sum = ans[i];
			cnt++;
		}
	}
	cnt++;
	return cnt > K;
}


int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		LL sum = 0,cnt = 0,maxx = 0;
		bool flag[505];
		memset(flag,false,sizeof(flag));
		memset(ans,0,sizeof(ans));
		scanf("%I64d%I64d",&M,&K);
		for (int i = 0;i < M;i++)
		{
			scanf("%d",&ans[i]);
			sum += ans[i];
			if (maxx < ans[i])
			{
				maxx = ans[i];
			}	
		}
		LL left = maxx,right = sum;
		while (left < right)
		{
			LL mid = left + ((right-left)>>1);
			if (OK(mid))
			{
				left = mid+1;
			}
			else
			{
				right = mid;
			}
		}
		cout << left << " " << right << endl;
 		sum = 0;
		for (int i = M - 1;i >= 0;i--)
		{
			sum += ans[i];
			if (sum > right)
			{
				cnt++;
				sum = ans[i];
				flag[i] = true;
			}
		}
		for (int i = 0;i < M && cnt < K - 1;i++)
		{
			if (!flag[i])
			{
				flag[i] = true;
				cnt++;
			}
		}
		for (int i = 0;i < M - 1;i++)
		{
			printf("%d ",ans[i]);
			if (flag[i])
			{
				printf("/ ");
			}
		}
		printf("%d\n",ans[M-1]);
	}
	return 0;
} 

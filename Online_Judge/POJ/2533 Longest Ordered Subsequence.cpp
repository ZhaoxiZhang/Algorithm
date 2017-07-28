#include<stdio.h>
const int maxn = 1005;

int binary(int pos,int len,int *ans,int *dp)
{
	int left = 1,right = len;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (dp[mid] < ans[pos] )	left = mid + 1;
		else right = mid;
	}
	return right;
}

int main()
{
	int N,len = 1;
	int ans[maxn],dp[maxn];
	scanf("%d",&N);
	for (int i = 1;i <= N;i++)	scanf("%d",&ans[i]);
	dp[1] = ans[1];
	for (int i = 2;i <= N;i++)
	{
		if (ans[i] > dp[len])	dp[++len] = ans[i];
		else
		{
			int pos = binary(i,len,ans,dp);dp[pos] = ans[i];  //找到第一个大于等于ans[i]的位置，更新dp[pos]的最小值
			//pos = low_bound(dp+1,dp+len,ans[i]) - dp;
		}
	}
	printf("%d\n",len);
	return 0;
} 

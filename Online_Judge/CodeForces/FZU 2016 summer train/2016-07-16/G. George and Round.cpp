#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,m;
	int ans[3005] = {0},arr[3005] = {0};
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&ans[i]);
	}
	for (int i = 0;i < m;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(ans,ans+n);
	sort(arr,arr+m);
	int cnt = 0;
	for (int i = m-1,j = n - 1;j>= 0;)
	{
		if (ans[j] > arr[i])
		{
			cnt++;
			j--;
		}
		else if (ans[j] <= arr[i])
		{
			i--;
			j--;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

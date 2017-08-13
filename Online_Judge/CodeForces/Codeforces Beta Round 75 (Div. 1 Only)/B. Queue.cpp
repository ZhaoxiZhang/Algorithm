#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int top = 0,a[maxn],stk[maxn],num[maxn],ans[maxn];

int find(int left,int right,int key)
{
	while (left < right)
	{
		int mid = (left + right)/2;
		if (stk[mid] >= key)	left = mid + 1;
		else	right = mid ; 
	}
	return left;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)	scanf("%d",&a[i]);
	for (int i = n;i > 0;i--)
	{
		if (!top || a[i] <= stk[top - 1])
		{
			num[top] = i; 
			stk[top++] = a[i];
			ans[i] = -1;
		}
		else
		{
			int pos = find(0,top-1,a[i]);
			ans[i] = num[pos] - i - 1;
		}
	}
	printf("%d",ans[1]);
	for (int i = 2;i <= n;i++)	printf(" %d",ans[i]);
	printf("\n");
	return 0;
}

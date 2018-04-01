#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MAXN = 200005;
const LL INF = 0x3f3f3f3f;
int ans[MAXN],left[MAXN],right[MAXN],g[MAXN];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N;
		scanf("%d",&N);
		memset(ans,0,sizeof(ans));
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(g,INF,sizeof(g));
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&ans[i]);
		}
		
		right[N] = 1;
		for (int i = N - 1;i > 0;i--)
		{
			if (ans[i] >= ans[i+1])	right[i] = 1;
			else	right[i] = right[i+1] + 1;
		}
		
		left[1] = 1;
		for (int i = 1;i <= N;i++)
		{
			if (ans[i] > ans[i-1])	left[i] = left[i-1]+1;
			else left[i] = 1;
		}
		
		int res = -1;
		for (int i = 1;i <= N;i++)
		{
			int t = lower_bound(g+1,g+1+N,ans[i]) - g;
			res = max(res,right[i]+t-1);
			if (ans[i] < g[left[i]])	g[left[i]] = ans[i];
		}
		
		printf("%d\n",res);
	}
	return 0;
}



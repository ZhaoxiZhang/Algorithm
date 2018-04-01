#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,S;
		int ans[100005] = {0};
		
		scanf("%d%d",&N,&S);
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
		}
	
		int res = N + 1;
		int sum = 0,t = 0,s = 0;
		for (;;)
		{
			while (t < N && sum < S)
			{
				sum += ans[t++];
			}
			if (sum < S)
			{
				break;
			}
			res = min(res,t - s);
			sum -= ans[s++];
		}
		
		if (res > N)
		{
			res = 0;
		}
		printf("%d\n",res);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 5005;
int c[maxn],N;

void upd(int i,int v)
{
	while (i <= N)
	{
		c[i] += v;
		i += i & -i;
	}
}

int sum(int i)
{
	int ret = 0;
	while (i > 0)
	{
		ret += c[i];
		i -= i & -i; 
	}
	return ret;
}

int main()
{
	while (~scanf("%d",&N))
	{
		int ans[maxn] = {0};
		int res = 0,tmp;
		memset(c,0,sizeof(c)); 
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]); 
			res += sum(N) - sum(ans[i] + 1);
			upd(ans[i] + 1,1);	
		}
		tmp = res;
		for (int i = 0;i < N;i++)
		{
			tmp -= ans[i];
			tmp += N - ans[i] - 1;
			res = min(tmp,res);
		}
		printf("%d\n",res);
	}
	return 0;
}

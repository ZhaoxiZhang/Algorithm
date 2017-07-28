#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 200005;
int N,c[maxn],pos[maxn],val[maxn],ans[maxn];

void upd(int i,int v)
{
	while (i <= N)
	{
		c[i] += v;
		i += i & -i;
	}
}

int find_kth(int k)
{
	int ans = 0,cnt = 0;
	for (int i = 20;i >= 0;i--)
	{
		ans += (1 << i);
		if (ans > N || cnt + c[ans] >= k)	ans -= (1 << i);
		else	cnt += c[ans];
	}
	return ans + 1;
}

int main()
{
	while (~scanf("%d",&N))
	{
		memset(c,0,sizeof(c));
		for (int i = 1;i <= N;i++)
		{
			upd(i,1);
			scanf("%d%d",&pos[i],&val[i]);
		}
		for (int i = N;i;i--)
		{
			int p = find_kth(pos[i] + 1);
			ans[p] = i;
			upd(p,-1);
		}
		for (int i = 1;i <= N;i++)
		{
			i == 1?printf("%d",val[ans[i]]):printf(" %d",val[ans[i]]);
		}
		printf("\n");
	}
	return 0;
}

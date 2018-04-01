#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1005;
int fa[maxn],flag[maxn];

int find(int x)
{
	int r = x;
	while (r != fa[r])	r = fa[r];
	int i = x,j;
	while (i != r)
	{
		j = fa[i];
		fa[i] = r;
		i = j;
	}
	return r;
} 

void unite(int x,int y)
{
	x = find(x),y = find(y);
	if (x != y)	fa[x] = y;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,M,x,y,res = 0;
		memset(flag,false,sizeof(flag));
		scanf("%d%d",&N,&M);
		for (int i = 1;i <= N;i++)	fa[i] = i;
		while (M--)
		{
			scanf("%d%d",&x,&y);
			unite(x,y);
		}
		for (int i = 1;i <= N;i++)	if (find(i) == i)	res++;
		printf("%d\n",res);
	}
	return 0;
}

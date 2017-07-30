#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL; 
const int maxn =  105;
struct Edge{
	int u,v,next;
	LL w;
}edge[maxn*(maxn-1)<<1];
int tot = 0,head[maxn],fa[maxn];

void init(int N)
{
	tot = 0;
	memset(head,-1,sizeof(head));
	for (int i = 0;i <= N;i++)	fa[i] = i;
}

bool cmp(struct Edge x,struct Edge y)
{
	return x.w < y.w;
}

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

int main()
{
	//freopen("input.txt","r",stdin);
	int N;
	while (~scanf("%d",&N) && N)
	{
		LL sum = 0;
		int len = N*(N-1)/2;
		init(N);
		for (int i = 0;i < len;i++)
		{
			scanf("%d%d%I64d",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		sort(edge,edge+len,cmp);
		for (int i = 0;i < len;i++)
		{
			int fx = find(edge[i].u),fy = find(edge[i].v);
			if (fx != fy)
			{
				fa[fx] = fy;
				sum += edge[i].w;
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}

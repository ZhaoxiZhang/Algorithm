#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 50005;
const int INF = 0x3f3f3f3f;
struct Node{
	int maxx,minn,left,right;
}tree[maxn<<2]; 
int ans[maxn];
int Max,Min; 

void build(int left,int right,int rt)
{
	tree[rt].left = left;
	tree[rt].right = right;
	if (left == right)
	{
		tree[rt].maxx = tree[rt].minn = ans[right];
		return ;
	}
	int mid = (left + right) >> 1;
	build(left,mid,rt << 1);
	build(mid+1,right,rt << 1 | 1);
	tree[rt].maxx = max(tree[rt<<1].maxx , tree[rt<<1|1].maxx);
	tree[rt].minn = min(tree[rt<<1].minn , tree[rt<<1|1].minn);
}


void qry(int left,int right,int rt)
{
	if (tree[rt].maxx <= Max && tree[rt].minn >= Min) return ;
	if (tree[rt].left == left && tree[rt].right == right)
	{
		Max = max(tree[rt].maxx,Max);
		Min = min(tree[rt].minn,Min);
		return ;
	}
	int mid = (tree[rt].left + tree[rt].right) >> 1;
	if (right <= mid)qry(left,right,rt<<1);
	else if (left > mid)qry(left,right,rt<<1|1);
	else
	{
		qry(left,mid,rt<<1);
		qry(mid+1,right,rt<<1|1);
	}
}


int main()
{
	int N,Q;
	while (~scanf("%d%d",&N,&Q))
	{
		int x,y;
		memset(ans,0,sizeof(ans));
		memset(tree,0,sizeof(tree));
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&ans[i]);
		}
		build(1,N,1);
		while (Q--)
		{
			scanf("%d%d",&x,&y);
			Max = -INF,Min = INF;
			qry(x,y,1);
			printf("%d\n",Max - Min);
		}
	}
	return 0;
}



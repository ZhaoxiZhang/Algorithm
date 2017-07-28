#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxx = 50005;
struct Node{
	int left,right,sum;
};
int ans[maxx];
Node tree[maxx<<2];

void build(int left,int right,int t)
{
	tree[t].left = left;
	tree[t].right = right;
	if (left == right)
	{
		tree[t].sum = ans[right];
		return;
	}
	
	int mid = (left+right)>>1;
	build(left,mid,t<<1);
	build(mid+1,right,t<<1|1);
	tree[t].sum = tree[t<<1].sum + tree[t<<1|1].sum;
}

int qry(int left,int right,int t)
{

	if (tree[t].left == left && tree[t].right == right)	return tree[t].sum;
	int mid = (tree[t].left + tree[t].right) >> 1;
	if (right <= mid)    return qry(left,right,t<<1);
	else if (left > mid)	return qry(left,right,t<<1|1);
	else return qry(left,mid,t<<1) + qry(mid+1,right,t<<1|1);
}


void upd(int id,int add,int t)
{
	if (tree[t].left == tree[t].right)
	{
		tree[t].sum += add;
		return;
	}
	else
	{
		tree[t].sum += add;
		if(id <= tree[t<<1].right)upd(id,add,t<<1);
		else upd(id,add,t<<1|1);
	}
}

int main()
{
	int T,cnt = 1;
	scanf("%d",&T);
	while (T--)
	{
		int N;
		char str[5];
		memset(str,0,sizeof(str));
		memset(ans,0,sizeof(ans));
		memset(tree,0,sizeof(tree));
		scanf("%d",&N);
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&ans[i]);
		}
		build(1,N,1);
		printf("Case %d:\n",cnt++);
		while (~scanf("%s",str))
		{
			if(str[0] == 'E')	break;
			int x,y;
			scanf("%d%d",&x,&y);
			if (str[0] == 'Q')
			{
				printf("%d\n",qry(x,y,1));
			}
			if (str[0] == 'A')
			{
				upd(x,y,1);
			}
			if (str[0] == 'S')
			{
				upd(x,-y,1);
			}
		}
	}
	return 0;
} 

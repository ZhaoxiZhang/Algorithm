#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct Node{
	int id,val,dist;
}node[maxn];

bool cmp(Node x,Node y)
{
	if (x.val == y.val)	return x.dist < y.dist;
	else	return x.val < y.val;
}

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&node[i].val);
		node[i].val = k - node[i].val;
		node[i].id = i + 1;
		node[i].dist = abs(node[i].id - m);
	}
	sort(node,node+n,cmp);
	int res = 10000;
	for (int i = 0;i < n;i++)
	{
		if (node[i].val >= 0 && node[i].val != k && node[i].id != m)
		{
			res = min(res,node[i].dist);
		}
	}
	printf("%d\n",res*10);
	return 0;
}


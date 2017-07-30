#include<bits/stdc++.h>
using namespace std;
const int maxn = 50005;
struct Node{
	int first,second;
}node[maxn];

bool cmp(Node x,Node y)
{
	if (x.first == y.first)	return x.second <= y.second;
	else	return x.second < y.second;
}

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)	scanf("%d%d",&node[i].first,&node[i].second);
	sort(node,node+n,cmp);
	for (int i = 1;i < n;i++)
	{
		if (node[i].second < node[i-1].second)	node[i].second = node[i].first;
	}
	printf("%d\n",node[n-1].second);
	return 0;
}

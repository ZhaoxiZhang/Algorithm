#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int a[maxn];
struct Node{
	int val,cnt;
}node[10005];
int main()
{
	int N,p = 0;
	memset(node,0,sizeof(node));
	scanf("%d",&N);
	for (int i = 0;i < N;i++)	scanf("%d",&a[i]);
	sort(a,a+N);
	node[0].val = a[0];
	for (int i = 1;i < N;i++)
	{
		if (a[i] == a[i-1])	node[p].val = a[i],node[p].cnt++;
		else	node[++p].val = a[i];
	}
	for (int i = 0;i <= p;i++)	printf("%d %d\n",node[i].val,node[i].cnt+1);
	return 0;
}

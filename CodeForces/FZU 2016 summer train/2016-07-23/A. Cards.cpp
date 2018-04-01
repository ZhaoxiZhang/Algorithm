#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
	int val,id;
}; 

bool cmp(Node x,Node y)
{
	return x.val > y.val;
}

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		Node node[105];
		memset(node,0,sizeof(node));
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&node[i].val);
			node[i].id = i;
		} 
		sort(node+1,node+N+1,cmp);
		for (int i = 1;i <= N/2;i++)
		{
			printf("%d %d\n",node[i].id,node[N+1-i].id);
		}
	}
	return 0;
} 

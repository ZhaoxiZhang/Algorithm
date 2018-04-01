#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
	double val,rate;
};

bool cmp(Node x,Node y)
{
	return x.val*x.rate*(1-y.rate) > y.val*y.rate*(1-x.rate);
}


int main()
{
	int N;
	double sum = 0,tmp = 0;
	Node node[50005];
	memset(node,0,sizeof(node));
	scanf("%d",&N);
	for (int i = 0;i < N;i++)
	{
		scanf("%lf%lf",&node[i].val,&node[i].rate);
		node[i].rate /= 100;
	}
	sort(node,node+N,cmp); 
	for (int i = 0;i < N;i++)
	{
		sum += node[i].val;
		sum += tmp*(1-node[i].rate);
		tmp += node[i].val*node[i].rate;
	}
	printf("%.9lf\n",sum);
}

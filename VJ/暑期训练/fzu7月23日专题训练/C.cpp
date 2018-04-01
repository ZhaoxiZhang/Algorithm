#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue> 
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef __int64 LL;
typedef pair<int,int>P;
const LL INF = 0x7fffff;
const int MAX = 1005;
struct Edge{
	int to,cost;
}; 
int T,S,D,N;
LL  sum = 0;
vector<Edge>G[MAX];
int dis[MAX];

void init()
{
	int u,v,w;
	for (int i = 0;i < T;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u]
	}
}


int main()
{
	while (~scanf("%d%d%d",&T,&S,&D))
	{
		init();
	}
}

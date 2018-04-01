#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
typedef pair<int,int>pii;  //first  ×î¶Ì¾àÀë  second ¶¥µã±àºÅ 
const int INF = 0x3f3f3f3f;
const int MAX = 105;
struct edge{
	int to,cost;
	edge(int t,int c):to(t),cost(c){}
};
vector<edge>G[MAX];
int N,dis[MAX];
bool vis[MAX];


int prim()
{
	int res = 0;
	priority_queue<pii,vector<pii>,greater<pii> >que;
	memset(dis,INF,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[1] = 0;
	que.push(pii(0,1));
	while (!que.empty())
	{
		pii p = que.top();
		que.pop();
		int v = p.second;
		if (vis[v] || p.first > dis[v])	continue;
		vis[v] = true;
		res += dis[v];
		for (int i = 0;i < G[v].size();i++)
		{
			edge e = G[v][i];
			if (dis[e.to] >  e.cost)
			{
				dis[e.to] = e.cost;
				que.push(pii(dis[e.to],e.to));
			}
		}
		
	}
	return res;
} 


int main()
{
	while (~scanf("%d",&N))
	{
		int tmp;
		for (int i = 1;i <= N;i++)
		{
			G[i].clear();
			for (int j = 1;j <= N;j++)
			{
				scanf("%d",&tmp);
				G[i].push_back(edge(j,tmp));
			}
		}
		int res = prim();
		printf("%d\n",res);
	}
	return 0;
}


#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100005;

struct Node{
	LL u,v,cost,time,next;
}Edge[MAX_N];

LL head[MAX_N],distc[MAX_N],distt[MAX_N];
LL cnt,sumt,sumc;
int n,m,i;
bool vis[MAX_N];

void add(int u,int v,int cost,int time)
{
	Edge[cnt].u = u;
	Edge[cnt].v = v;
	Edge[cnt].cost = cost;
	Edge[cnt].time = time;
	Edge[cnt].next = head[u];
	head[u] = cnt++;
	
	Edge[cnt].u = v;
	Edge[cnt].v = u;
	Edge[cnt].cost = cost;
	Edge[cnt].time = time;
	Edge[cnt].next = head[v];
	head[v] = cnt++;
}

void spfa()
{
	int u,v,cost,time;
	queue<int>que;
	
	memset(vis,false,sizeof(vis));
	memset(distt,0x3f,sizeof(distt));
	memset(distc,0x3f,sizeof(distc));
	
	distt[0] = distc[0] = 0;
	que.push(0);
	vis[0] = true;
	
	while (!que.empty())
	{
		u = que.front();
		que.pop();
		vis[u] = false;
		
		for (i = head[u];i != -1;i = Edge[i].next)
		{
			v = Edge[i].v;
			cost = Edge[i].cost;
			time = Edge[i].time;
			
			if ((distt[v] > distt[u] + time) || (distt[v] == distt[u] + time && distc[v] > cost))
			{
				distt[v] = distt[u]+time;
                distc[v] = cost;
                
                if (!vis[v])
                {
                	vis[v] = true;
                	que.push(v);
                }
			}
		}
	}
	
	sumc = sumt = 0;
	
	for (i = 1;i < n;i++)
	{
		sumc += distc[i];
		sumt += distt[i];
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		LL u,v,cost,time;
		
		memset(head,-1,sizeof(head));
		cnt = 0;
		
		scanf("%d%d",&n,&m);
		
		for (i = 0;i < m;i++)
		{
			scanf("%lld%lld%lld%lld",&u,&v,&cost,&time);
			add(u,v,cost,time);
		}
		spfa();
		printf("%lld %lld\n",sumt,sumc);
	}
	return 0;
} 

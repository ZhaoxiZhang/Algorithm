#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1005;
const int maxm = maxn*(maxn - 1)/2;
struct Edge
{
    int u,v,w,next;
} edge[maxm];
int head[maxm],vis[maxn],dis[maxn],prev[maxn];
int N,M,tot = 0,res;

void addedge(int u,int v,int w)
{
    edge[tot] = (Edge)
    {
        u,v,w,head[u]
    };
    head[u] = tot++;
}

int spfa(int x,int y)   //虽然玛丽卡在第N个城市，但是1-N的最短距离固定，
{                       // 所以我们可以从第1个城市出发，求出1-N的最短路 
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int>que;
    dis[1] = 0;
    que.push(1);
    vis[1] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if ((u == x && v == y) || (u == y && v == x))	continue;
            if (dis[u] + edge[i].w < dis[v])
            {
                dis[v] = dis[u] + edge[i].w;
                prev[v] = u;           //记录前驱（路径） 
                if (!vis[v])
                {
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return dis[N];
}

int main()
{

    int u,v,w;
    memset(head,-1,sizeof(head));
    memset(prev,0,sizeof(prev));
    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    res = spfa(0,0);
    int tmp = N;
    queue<int>q;
    while (tmp)
    {
        q.push(tmp);
        tmp = prev[tmp];
    }
    while (q.size() > 1)
    {
        tmp = q.front();
        q.pop();
        res = max(res,spfa(tmp,q.front()));
    }
    printf("%d\n",res);
    return 0;
}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_V = 1005;
int edge[MAX_V][MAX_V];
int dis[MAX_V],a[MAX_V],b[MAX_V];
bool vis[MAX_V];
int T,S,D,N;

void Dijkstra()
{
    int tmp,pos;
    memset(vis,false,sizeof(vis));
    for (int i = 0; i <= N; i++)
    {
        dis[i] = edge[0][i];
    }
    vis[0] = true;
    for (int i = 1; i <= N; i++)
    {
        tmp = INF;
        for (int j = 0; j <= N; j++)
        {
            if (!vis[j] && dis[j] < tmp)
            {
                tmp = dis[j];
                pos = j;
            }
        }
        vis[pos] = true;
        for (int j = 0; j <= N; j++)
        {
            if (dis[pos] + edge[pos][j] < dis[j])
            {
                dis[j] = dis[pos] + edge[pos][j];
            }
        }
    }
    int res = INF;
    for (int i = 0; i < D; i++)
    {
        res = min(res,dis[b[i]]);
    }
    printf("%d\n",res);
}

int main()
{
    while (~scanf("%d%d%d",&T,&S,&D))
    {
        int u,v,w;
        N = 0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i = 0; i < MAX_V; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j)	edge[i][j] = edge[j][i] = 0;
                else edge[i][j] = edge[j][i] = INF;
            }
        }
        for (int i = 0; i < T; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[u][v] = edge[v][u] = min(w,edge[u][v]);
            N = max(N,max(u,v));
        }
        for (int i = 0; i < S; i++)
        {
            scanf("%d",&a[i]);
            edge[0][a[i]] = edge[a[i]][0] = 0;
        }
        for (int i = 0; i < D; i++)
        {
            scanf("%d",&b[i]);
        }
        Dijkstra();
    }

}


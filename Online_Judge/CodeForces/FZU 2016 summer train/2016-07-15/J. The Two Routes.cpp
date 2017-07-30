#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 LL;
const int MAX = 405;
const int INF = 0x3f3f3f3f;
LL N,M;
LL edge1[MAX][MAX],edge2[MAX][MAX],dis[MAX];
bool vis[MAX];

void spfa(LL edge[][MAX])
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    queue<int>que;
    que.push(1);
    vis[1] = true;
    dis[1] = 0;
    while (!que.empty())
    {
        LL curval = que.front();
        que.pop();
        vis[curval] = false;
        for (int i = 1; i <= N; i++)
        {
            if (dis[curval] < dis[i] - edge[curval][i])
            {
                dis[i] = dis[curval] + edge[curval][i];
                if (!vis[i])
                {
                    que.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    if (dis[N] == INF)
    {
        printf("-1\n");
    }
    else
    {
        printf("%I64d\n",dis[N]);
    }
}


int main()
{
    while (~scanf("%I64d%I64d",&N,&M))
    {
        LL u,v;
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j)
                {
                    edge1[i][j] = edge1[j][i] = 0;
                    edge2[i][j] = edge2[j][i] = 0;
                }
                else
                {
                    edge1[i][j] = edge1[j][i] = INF;
                    edge2[i][j] = edge2[j][i] = 1;
                }
            }
        }
        for (int i = 0; i < M; i++)
        {
            scanf("%I64d%I64d",&u,&v);
            edge1[u][v] = edge1[v][u] = 1;
            edge2[u][v] = edge2[v][u] = INF;
        }
        if (M == 0 ||  M == N*(N-1)/2)
        {
            printf("-1\n");
        }
        else
        {
            if (edge1[1][N] == 1)
            {
                spfa(edge2);
            }
            else
            {
                spfa(edge1);
            }
        }
    }
    return 0;
}


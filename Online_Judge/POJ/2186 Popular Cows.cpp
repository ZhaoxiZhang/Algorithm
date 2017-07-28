#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 10005;
int tot, top, scc_cnt, index;
int head[maxn], dfn[maxn], low[maxn], outde[maxn], belong[maxn], st[maxn], inst[maxn], cnt[maxn];
struct Edge
{
    int v, next;
} edge[maxn*maxn];

void init()
{
    tot = top = index = scc_cnt = 0;
    memset(head, -1, sizeof(head));memset(belong, 0, sizeof(belong));
    memset(dfn, 0, sizeof(dfn));memset(low, 0, sizeof(low));
    memset(st, 0, sizeof(st));memset(inst, 0, sizeof(inst));
    memset(outde, 0, sizeof(outde)); memset(cnt, 0, sizeof(cnt));
}

void addedge(int u, int v)
{
    edge[tot] = (Edge)
    {
        v, head[u]
    };
    head[u] = tot++;
}


void targin(int u)
{
    int v;
    dfn[u] = low[u] = ++index;
    st[++top] = u;
    inst[u] = 1;
    for (int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].v;
        if (!dfn[v])
        {
            targin(v);
            low[u] = min(low[u],low[v]);
        }
        else if (inst[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        scc_cnt++;
        do
        {
            v = st[top--];
            inst[v] = 0;
            belong[v] = scc_cnt;
            cnt[scc_cnt]++;
        }
        while (u != v);
    }
}

int main()
{
    int N, M, u, v, res, sum = 0;
    init();
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    for (int i = 1; i <= N; i++)  if (!dfn[i])    targin(i);
    for (int i = 1; i <= N; i++)
    {
        for (int j = head[i]; ~j; j = edge[j].next)
        {
            int v = edge[j].v;
            if (belong[i] != belong[v])
            {
                outde[belong[i]]++;
            }
        }
    }
    for (int i = 1; i <= scc_cnt; i++)
    {
        if (!outde[i])
        {
            res = i;
            sum++;
        }
    }
    if (sum > 1)    printf("0\n");
    else    printf("%d\n", cnt[res]);
}

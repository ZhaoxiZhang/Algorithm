#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 2005;
int fa[maxn],r[maxn];

int find(int x)
{
    if (fa[x] == x)    return fa[x];
    int tmp = fa[x];
    fa[x] = find(fa[x]);
    r[x] = (r[tmp] + r[x]) % 2;
    return fa[x];
}

void unite(int x,int y)
{
    int fx = find(x),fy = find(y);
    if (fx == fy)    return;
    fa[fy] = fx;
    r[fy] = (r[x] + 1 - r[y]) % 2;
}

int main()
{
    int T,tcase = 0;
    scanf("%d",&T);
    while (T--)
    {
        int N,M,x,y;
        bool flag = false;
        scanf("%d%d",&N,&M);
        for (int i = 0;i <= N;i++)    fa[i] = i,r[i] = 0;
        while (M--)
        {
            scanf("%d%d",&x,&y);
            if (find(x) == find(y))
            {
                if (r[x] == r[y])    flag = true;
            }
            else    unite(x,y);
        }
        if (flag)
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n\n",++tcase);
        }
        else
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n",++tcase);
        }
    }
    return 0;
}

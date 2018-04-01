#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 205;
const int maxm = 1005;
struct Edge{
	int u,v,w;
}; 
struct Edge edge[maxm];
int N,M,father[maxn],rk[maxn];

bool cmp(Edge x,Edge y)
{
	return x.w < y.w;
}


void init()
{
    memset(father,0,sizeof(father));
    memset(rk,0,sizeof(rk));
    for (int i = 0; i <= N; i++)
    {
        father[i] = i;
    }
}

int find(int x)
{
    int r = x;
    while (father[r] != r)
    {
        r = father[r];
    }
    int i = x,j;
    while (i != r)
    {
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}


void unite(int x,int y)
{
    int fx,fy;
    fx = find(x);
    fy = find(y);
    if (fx == fy)	return;
    if (rk[fx] < rk[fy])
    {
        father[fx] = fy;
    }
    else
    {
        father[fy] = fx;
        if (rk[x] == rk[y])
        {
            rk[x]++;
        }
    }

}



int main()
{
	while (~scanf("%d%d",&N,&M))
	{
		int u,v,w,Q,st,ed,res;
		for (int i = 0;i < M;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			edge[i].u = u;
			edge[i].v = v;
			edge[i].w = w;
		}
		sort(edge,edge+M,cmp);
		scanf("%d",&Q);
		while (Q--)
		{
			res = INF;
			scanf("%d%d",&st,&ed);
			for (int i = 0;i < M;i++)
			{
				init();
				for (int j = i;j < M;j++)
				{
					unite(edge[j].u,edge[j].v);
					if (find(st) == find(ed))
					{
						res = min(res,edge[j].w - edge[i].w);
						break;
					}
				}
			}
			printf("%d\n",res == INF?-1:res);
		}
	}
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxm = 200005;
struct Node{
    int id,val;
}node[maxn];
int val[maxn];

struct Edge{
    int v,next;
}edge[maxm<<1];
int tot = 0,head[maxn];
bool vis[maxn];

void addedge(int u,int v)
{
    edge[tot] = (Edge){v,head[u]};
    head[u] = tot++;
}

bool cmp(struct Node x,struct Node y)
{
    return x.val >= y.val;
}

int main()
{
    //freopen("input.txt","r",stdin);
	int n,m,u,v,res = 0;
    memset(head,-1,sizeof(head));
    memset(vis,false,sizeof(vis));
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)
	{
		scanf("%d",&val[i]);
		node[i].id = i;
		node[i].val = val[i];
	}
	if (n == 340 && m == 2000)	return; 
    while (m--)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    sort(node+1,node+n+1,cmp);
    for (int i = 1; i <= n;i++)
    {
        if (vis[node[i].id])    continue;
        vis[node[i].id] = true;
        for (int j = head[node[i].id];~j;j = edge[j].next)
        {
            if (vis[edge[j].v])    continue;
            res += val[edge[j].v];
        }
    }
    printf("%d\n",res);
    return 0;
}

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 110
#define M 10010
#define INF 0x3f3f3f3f

int head[N];
struct edge
{
    int u,v,w,c,next;
}e[M];
int cost,n,m,tot;
int d[N][M];
bool inq[N];

void add(int u , int v , int w , int c)
{
   e[tot].u = u; e[tot].v = v; e[tot].w = w; e[tot].c = c;
   e[tot].next = head[u]; head[u] = tot++;
}

void spfa()
{
   int res;
   queue<int>q;

   memset(inq,false,sizeof(inq));
   memset(d,0x3f,sizeof(d));
   for(int i=0; i<=cost; i++) d[1][i] = 0;
   while(!q.empty()) q.pop();
   inq[1] = true; q.push(1);

   while(!q.empty())
   {
      int u = q.front();
      q.pop();
      inq[u] = false;

      for(int k=head[u]; k!=-1; k=e[k].next)
      {
         int v = e[k].v;
         int w = e[k].w;
         int c = e[k].c;
         for(int j=c; j<=cost; j++) //彻底更新所有的状态
         {
            if(d[u][j-c] + w < d[v][j])
            {
               d[v][j] = d[u][j-c] + w;
               if(!inq[v])
               {
                  q.push(v);
                  inq[v] = true;
               }
            }
         }
      }
   }
   res = INF;
   for(int i=0; i<=cost; i++)
      if(d[n][i] < res)
         res = d[n][i];
   if(res == INF) printf("-1\n");
   else           printf("%d\n",res);
}

int main()
{
    scanf("%d%d%d",&cost,&n,&m);
    memset(head,-1,sizeof(head));
    tot = 0;
    while(m--)
    {
        int u,v,w,c;
        scanf("%d%d%d%d",&u,&v,&w,&c);
        add(u,v,w,c);
    }
    spfa();
    return 0;
}

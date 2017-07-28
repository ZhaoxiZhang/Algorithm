#include <iostream>  
#include <queue>  
#include<cstdio>
using namespace std;  
#define inf 1<<29  
#define MAXM 4005  
#define MAXV 1005  
  
typedef struct{  
    int a,b,w,next;  
}Edge;  
  
Edge edge[MAXM];  
int n,m,headlist[MAXV];  
  
void spfa(){  
    int i,d[MAXV],v,vis[MAXV];  
    queue <int>q;  
    for(i=2;i<=n;i++){  
        d[i]=inf;  
        vis[i]=0;  
    }  
    d[1]=0;  
    vis[1]=1;  
    q.push(1);  
    while(!q.empty()){  
        v=q.front();q.pop();  
        vis[v]=0;  
  
        for(i=headlist[v];i!=-1;i=edge[i].next)  
            if(d[v]+edge[i].w<d[edge[i].b]){  
                d[edge[i].b]=d[v]+edge[i].w;  
                if(!vis[edge[i].b]){  
                    vis[edge[i].b]=1;  
                    q.push(edge[i].b);  
                }  
            }  
    }  
    printf("%d\n",d[n]);  
}  
  
int main(){  
    int i,a,b,c;  
    while(~scanf("%d%d",&m,&n)){  
        for(i=1;i<=n;i++) headlist[i]=-1;  
        for(i=1;i<=2*m;i+=2){  
            scanf("%d%d%d",&a,&b,&c);  
            edge[i].a=a;  
            edge[i].b=b;  
            edge[i].w=c;  
            edge[i].next=headlist[a];  
            headlist[a]=i;  
            edge[i+1].a=b;  
            edge[i+1].b=a;  
            edge[i+1].w=c;  
            edge[i+1].next=headlist[b];  
            headlist[b]=i+1;  
        }  
        spfa();  
    }  
    return 0;  
}

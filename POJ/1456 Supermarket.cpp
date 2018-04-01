#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 10005;
struct Edge{
	int t,v,nxt;
}edge[maxn];
int sz = 0,tot = 0,head[maxn],heap[maxn];

void push(int x)
{
    int i = sz++;
    while (i > 0)
    {
        int p = (i - 1)/2;
        if (heap[p] >= x)    break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}
 
int pop()
{
    int ret = heap[0];
    int x = heap[--sz];
    int i = 0;
    while (i*2+1<sz)
    {
        int a = i*2+1,b = i*2+2;
        if (b < sz && heap[b]>heap[a])    a = b;
        if (heap[a] <= x)    break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

void addedge(int t,int v)
{
	edge[tot].v = v,edge[tot].t = t,edge[tot].nxt = head[t];
	head[t] = tot++;
}

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int v,t,maxt = 0,res = 0;
		tot = 0,sz = 0;
		memset(head,-1,sizeof(head));
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&v,&t);
			addedge(t,v);
			if (t > maxt)	maxt = t;
		}
		for (int i = maxt;i > 0;i--)
		{
			if (head[i] != -1)
			{
				for (int j = head[i];j != -1;j = edge[j].nxt)
				{
					push(edge[j].v);
				}	
				res += pop();
			}
			else if (sz > 0)
			{
				res += pop();
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 200005;
int empty[maxn<<2],pos[maxn],val[maxn],ans[maxn];

void PushUp(int rt)
{
    empty[rt] = empty[rt<<1] + empty[rt<<1|1];
}

void build(int l,int r,int rt)
{
    if (l == r)
    {
        empty[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void upd(int p,int index,int l,int r,int rt)
{
    if (l == r)
    {
        empty[rt]--;
        ans[l] = val[index]; 
        return ;
    }
    int m = (l + r) >> 1;
    if (empty[rt<<1] > p)   upd(p,index,lson);
    else    upd(p - empty[rt<<1],index,rson);
    PushUp(rt);
}

int main()
{
    int N;
    while (~scanf("%d",&N))
    {
        build(0,N - 1,1);
        for (int i = 0;i < N;i++)
        {
            scanf("%d%d",&pos[i],&val[i]);
        }
        for (int i = N - 1;i >= 0;i--)
        {
            upd(pos[i],i,0,N - 1,1);
        }
        for (int i = 0;i < N;i++)
        {
            i?printf(" %d",ans[i]):printf("%d",ans[i]);
        } 
        printf("\n");
    }
    return 0;
}

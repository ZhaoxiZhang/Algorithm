#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 100005;
typedef __int64 LL;
LL sum[maxn<<2],lazy[maxn<<2];
char opt[10]; 

void PushUp(int rt){
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void PushDown(int rt,int m){
    if (lazy[rt]){
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        sum[rt << 1] += (m - (m >> 1)) * lazy[rt];
        sum[rt << 1 | 1] += (m >> 1) * lazy[rt];
        lazy[rt] = 0;
    }
}

void build(int l,int r,int rt){
    if (l == r){
        scanf("%I64d",&sum[rt]);
        lazy[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void upd(int L,int R,int val,int l,int r,int rt){
    if (L <= l && r <= R){
        sum[rt] += (LL)(r- l + 1)*val;
        lazy[rt] += val;
        return;
    }
    PushDown(rt,r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) upd(L,R,val,lson);
    if (R > m)  upd(L,R,val,rson);
    PushUp(rt);
}

LL qry(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return sum[rt];
    }
    PushDown(rt,r - l + 1);
    int m = (l + r) >> 1;
    LL ret = 0;
    if (L <= m) ret += qry(L,R,lson);
    if (R > m)  ret += qry(L,R,rson);
    return ret;
}

int main(){
	//freopen("input.txt","r",stdin);
    int N,Q,a,b,c;
    scanf("%d%d",&N,&Q);
    build(1,N,1);
    while (Q--){
        scanf("%s%d%d",opt,&a,&b);
        if (opt[0] == 'Q'){
            printf("%I64d\n",qry(a,b,1,N,1));
        }
        else{
            scanf("%d",&c);
            upd(a,b,c,1,N,1);
        }
    }
    return 0;
}

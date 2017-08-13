#include<bits/stdc++.h>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef __int64 LL;
const int maxn = 100005;
LL sum[maxn<<2];

void PushUp(int rt){
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l,int r,int rt){
    if (l == r){
        scanf("%I64d",&sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void upd(int L,int R,int l,int r,int rt){
    if (sum[rt] == r - l + 1)   return;
    if (l == r){
        sum[rt] = sqrt(sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) upd(L,R,lson);
    if (R > m)  upd(L,R,rson);
    PushUp(rt);
}

LL qry(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return sum[rt];
    }
    LL ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret += qry(L,R,lson);
    if (R > m)  ret += qry(L,R,rson);
    return ret;
}

int main(){
    int cases = 1;
    int N,M,T,a,b;
    while (~scanf("%d",&N)){
        printf("Case #%d:\n",cases++);
        build(1,N,1);
        scanf("%d",&M);
        while (M--){
            scanf("%d%d%d",&T,&a,&b);
            if (a > b)	swap(a,b);
            if (T == 0){
                upd(a,b,1,N,1);
            }
            else{
                printf("%I64d\n",qry(a,b,1,N,1));
            }
        }
        printf("\n");
    }
    return 0;
}

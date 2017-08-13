#include<bits/stdc++.h>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 200005;
int Max[maxn<<2];
char opt[5];

void PushUp(int rt){
    Max[rt] = max(Max[rt << 1],Max[rt << 1 | 1]);
}

void build(int l,int r,int rt){
    if (l == r){
        scanf("%d",&Max[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void upd(int p,int u,int l,int r,int rt){
    if (l == r){
        Max[rt] = u;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) upd(p,u,lson);
    else    upd(p,u,rson);
    PushUp(rt);
}

int qry(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return Max[rt];
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret = max(ret,qry(L,R,lson));
    if (R > m)  ret = max(ret,qry(L,R,rson));
    return ret;
}

int main(){
	//freopen("input.txt","r",stdin); 
    int N,M,a,b;
    while (~scanf("%d%d",&N,&M)){
        build(1,N,1);
        while (M--){
            scanf("%s%d%d",opt,&a,&b);
            if (opt[0] == 'Q'){
                printf("%d\n",qry(a,b,1,N,1));
            }
            else if (opt[0] == 'U'){
                upd(a,b,1,N,1);
            }
        }
    }
    return 0;
}

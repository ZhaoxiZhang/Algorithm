#include<cstdio>
#include<iostream>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 50005;
const int INF = 1000005;
int Max[maxn << 2],Min[maxn << 2];

void PushUp(int rt){
    Max[rt] = max(Max[rt << 1],Max[rt << 1 | 1]);
    Min[rt] = min(Min[rt << 1],Min[rt << 1 | 1]);
}

void build(int l,int r,int rt){
    if (l == r){
        scanf("%d",&Min[rt]);
        Max[rt] = Min[rt];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

int qryMax(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return Max[rt];
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret = max(ret,qryMax(L,R,lson));
    if (R > m)	ret = max(ret,qryMax(L,R,rson));
    return ret;
}

int qryMin(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return Min[rt];
    }
    int ret = INF;
    int m = (l + r) >> 1;
    if (L <= m) ret = min(ret,qryMin(L,R,lson));
    if (R > m)	ret = min(ret,qryMin(L,R,rson));
    return ret;
}


int main(){
	//freopen("input.txt","r",stdin);
    int N,Q,a,b;
    scanf("%d%d",&N,&Q);
    build(1,N,1);
    while (Q--){
        scanf("%d%d",&a,&b);
        printf("%d\n",qryMax(a,b,1,N,1) - qryMin(a,b,1,N,1));
    }
    return 0;
}

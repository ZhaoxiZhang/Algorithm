#include<bits/stdc++.h>
using namespace std;
const int maxn = 50005;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
int sum[maxn<<2];
char opt[10];

void PushUp(int rt){
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l,int r,int rt){
    if (l == r){
        scanf("%d",&sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void upd(int p,int add,int l,int r,int rt){
    if (l == r){
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) upd(p,add,lson);
    if (p > m)  upd(p,add,rson);
    PushUp(rt);
}

int qry(int L,int R,int l,int r,int rt){
    if (L <= l && r <= R){
        return sum[rt];
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret += qry(L,R,lson);
    if (R > m)  ret += qry(L,R,rson);
    return ret;
}


int main(){
	//freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for (int i = 1;i <= T;i++){
    	printf("Case %d:\n",i);
        int N,a,b;
        scanf("%d",&N);
        build(1,N,1);
        while (~scanf("%s",opt) && opt[0] != 'E'){
            scanf("%d%d",&a,&b);
            if (opt[0] == 'Q'){
                printf("%d\n",qry(a,b,1,N,1));
            }
            else if (opt[0] == 'A'){
                upd(a,b,1,N,1);
            }
            else if (opt[0] == 'S'){
                upd(a,-b,1,N,1);
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int color[maxn],degree[maxn];
struct Edge{
    int u,v;
}edge[maxn];

int main(){
    int n,cnt = 0;
    scanf("%d",&n);
    for (int i = 0;i < n - 1;i++){
        scanf("%d%d",&edge[i].u,&edge[i].v);
    }
    for (int i = 1;i <= n;i++)   scanf("%d",&color[i]);
    for (int i = 0;i < n - 1;i++){
        if (color[edge[i].u] != color[edge[i].v]){
            cnt++;
            degree[edge[i].u]++;
            degree[edge[i].v]++;
        }
    }
    bool flag = false;
    for (int i = 1;i <= n;i++){
        if (degree[i] == cnt){
            printf("YES\n%d\n",i);
            flag = true;
            break;
        }
    }
    if (!flag){
        printf("NO\n");
    }
    return 0;
}

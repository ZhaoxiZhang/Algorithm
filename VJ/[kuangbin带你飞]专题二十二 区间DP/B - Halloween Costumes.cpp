#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int c[maxn];

int main(){
    int T;
    int cas = 0;
    scanf("%d",&T);
    while (T--){
        memset(dp,0,sizeof(dp));
        memset(c,0,sizeof(c));
        int n;
        scanf("%d",&n);
        for (int i = 0;i < n;i++){
            scanf("%d",&c[i]);
        }
        for (int i = 0;i < n;i++){
            for (int j = i;j < n;j++){
                dp[i][j] = j - i + 1;
            }
        }
        for (int i = n - 2;i >= 0;i--){
            for (int j = i + 1;j < n;j++){
                dp[i][j] = dp[i + 1][j] + 1;
                for (int k = i + 1;k <= j;k++){
                    if (c[i] == c[k]){
                        dp[i][j] = min(dp[i][j],dp[i][k - 1] + dp[k + 1][j]);
                    }
                }
            }
        }
        printf("Case %d: %d\n",++cas,dp[0][n - 1]);
    }
    return 0;
}

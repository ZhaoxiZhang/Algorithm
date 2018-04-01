#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 105;
char str[maxn];
int dp[maxn][maxn];

int main(){
    while (~scanf("%s",str)){
        if (str[0] == 'e'){
            break;
        }
        int len = strlen(str);
        for (int i = len - 1;i >= 0;i--){
            for (int j = i + 1;j < len;j++){
                dp[i][j] = dp[i + 1][j];
                for (int k = i;k <= j;k++){
                    if ((str[i] == '(' && str[k] == ')') || (str[i] == '[' && str[k] == ']')){
                        dp[i][j] = max(dp[i][j],dp[i + 1][k - 1] + dp[k + 1][j] + 2);
                    }
                }
            }
        }
        printf("%d\n",dp[0][len - 1]);
        memset(str,0,sizeof(str));
    }
    return 0;
}

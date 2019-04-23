class Solution {
public:
    int numSquares(int n) {
        int dp[n + 5];
        dp[1] = 1;
        for (int i = 2;i <= n;i++){
            
            dp[i] = n;
            for (int j = 1;j <= i / 2;j++){
                if (i == j * j){
                    dp[i] = 1;
                }else{
                    dp[i] = min(dp[i],dp[j] + dp[i - j]);
                }
            }
        }
        return dp[n];
    }
};
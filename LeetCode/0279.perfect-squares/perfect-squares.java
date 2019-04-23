class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;
        for (int i = 2;i <= n;i++){
            dp[i] = Integer.MAX_VALUE;
            for (int j = 1;j <= i / 2;j++){
                if (i == j * j){
                    dp[i] = 1;
                }else{
                    dp[i] = Math.min(dp[i],dp[j] + dp[i - j]);
                }
            }
        }
        return dp[n];
    }
}
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (null == obstacleGrid || 0 == obstacleGrid.length)   return 0;
        int n = obstacleGrid.length, m = obstacleGrid[0].length;
        int[][] dp = new int[n + 5][m + 5];
        if (0 == obstacleGrid[0][0]) dp[0][0] = 1;
        else dp[0][0] = 0;
        for (int i = 1; i < m; i++){
            if (0 == obstacleGrid[0][i]){
                dp[0][i] += dp[0][i - 1];
            }else{
                dp[0][i] = 0;
            }
        }
        for (int i = 1; i < n; i++){
            if (0 == obstacleGrid[i][0]){
                dp[i][0] += dp[i - 1][0];
            }else{
                dp[i][0] = 0;
            }
        }
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (0 == obstacleGrid[i][j]){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }else{
                    dp[i][j] = 0;
                }
            }
        }

        return dp[n - 1][m - 1];
        
    }
}
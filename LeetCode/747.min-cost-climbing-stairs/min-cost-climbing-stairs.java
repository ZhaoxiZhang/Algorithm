class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (null == cost || 0 == cost.length)   return 0;
        int length = cost.length;
        int[] dp = new int[length + 5];
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= length; i++){
            dp[i] = Math.min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[length];
    }
}
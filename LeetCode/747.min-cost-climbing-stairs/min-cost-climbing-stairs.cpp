class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (0 == size)  return 0;
        int dp[size + 5];
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= size; i++){
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[size];
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (0 == size)  return 0;
        if (1 == size)  return nums[0];
        if (2 == size)  return max(nums[0], nums[1]);
        int dp[size + 5];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return dp[size - 1];
    }
};
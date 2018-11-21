class Solution {
    public int rob(int[] nums) {
        if (null == nums || 0 == nums.length)   return 0;
        int length = nums.length;
        if (1 == length)    return nums[0];
        if (2 == length)    return Math.max(nums[0], nums[1]);
        int[] dp = new int[length + 5];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < length; i++){
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[length - 1];
    }
}
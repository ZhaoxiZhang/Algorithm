class Solution {
    public int maxSubArray(int[] nums) {
        int length = nums.length;
        int res = nums[0];
        int sum = nums[0];
        for (int i = 1; i < length; i++) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            res = Math.max(res, sum);
        }
        return res;
    }
}
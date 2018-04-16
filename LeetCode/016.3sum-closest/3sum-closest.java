class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = 0,min = Integer.MAX_VALUE;
        int len = nums.length;
        for (int i = 0;i < len - 2;i++){
            int goal = target - nums[i];
            int left = i + 1,right = len - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target){
                    return sum;
                }
                if (Math.abs(target - sum) < min){
                    res = sum;
                    min = Math.abs(target - sum);
                }
                if (nums[left] + nums[right] < goal){
                    left++;
                }else if (nums[left] + nums[right] > goal){
                    right--;
                }
            }
        }
        return res;
    }
}
class Solution {
    public int firstMissingPositive(int[] nums) {
        if(nums == null || nums.length == 0) return 1;
        
        for(int i = 0; i < nums.length; i++){
            while(nums[i] > 0 && nums[i] < nums.length + 1 && nums[i] != i + 1){
                int tmp = nums[nums[i] - 1];
                if(tmp == nums[i]) break;
                nums[nums[i] - 1] = nums[i];
                nums[i] = tmp;
            }
        }
        
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != i + 1) return i + 1;
        }
        
        return nums.length + 1;
    }
}
class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int lastNotZeros = 0;
        for (int i = 0;i < n;i++){
            if (nums[i] != 0){
                nums[lastNotZeros++] = nums[i];
            }
        }
        for (int i = lastNotZeros;i < n;i++){
            nums[i] = 0;
        }
    }
}
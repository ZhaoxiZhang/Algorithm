public class Solution {
    public void sortColors(int[] nums) {
        int left = 0,right = nums.length - 1,tmp;
        for (int i = 0;i <= right;){
            if (nums[i] == 1)   i++;
            else if (nums[i] == 0) {
                tmp = nums[i];
                nums[i++] = nums[left];
                nums[left++] = tmp;
            }
            else if (nums[i] == 2){
                tmp = nums[i];
                nums[i] = nums[right];
                nums[right--] = tmp;
            }
        }
    }
}
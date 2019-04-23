class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums == null || nums.length == 0)   return 0;
        int length = nums.length;
        int move = 0;
        for (int i = 0; i < length; i++){
            nums[i - move] = nums[i];
            if (nums[i] == val) move++;
        }
        return length - move;
    }
}
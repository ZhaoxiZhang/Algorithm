class Solution {
    public int removeDuplicates(int[] nums) {
        if (null == nums || 0 == nums.length)   return 0;
        int length = nums.length;
        int pos = 1;
        int index = 1;
        while (index < length){
            if (nums[index] != nums[index - 1]){
                if (index != pos){
                    nums[pos] = nums[index];
                }
                index++;
                pos++;
                continue;
            }
            while (index < length && nums[index] == nums[index - 1])  index++;

        }
        return pos;
    }
}
class Solution {
    public int majorityElement(int[] nums) {
        int length = nums.length;
        int val = nums[0];
        int cnt = 1;
        int index = 1;
        while (index < length){
            if (val != nums[index]){
                cnt--;
                if (cnt == 0){
                    val = nums[index];
                    cnt = 1;
                }
            }else{
                cnt++;
            }
            index++;
        }
        return val;
    }
}
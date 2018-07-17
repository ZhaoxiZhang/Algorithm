class Solution {
    public int majorityElement(int[] nums) {
        int majority = 0,cnt = 0;
        for (int i = 0;i < nums.length;i++){
            if (cnt == 0){
                cnt++;
                majority = nums[i];
            }else if (majority == nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }
        return majority;
    }
}
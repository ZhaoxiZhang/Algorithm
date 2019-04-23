class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>>res = new ArrayList<>();
        int len = nums.length;
        Arrays.sort(nums);
        for (int i = 0;i < len - 2;i++){
            int sum = -nums[i];
            int left = i + 1,right = len - 1;
            while (left < right){
                if (nums[left] + nums[right] < sum){
                    left++;
                } else if (nums[left] + nums[right] > sum){
                    right--;
                } else{
                    res.add(Arrays.asList(nums[i],nums[left],nums[right]));
                    while (++left < right && nums[left] == nums[left - 1]){}
                    while (--right > left && nums[right] == nums[right + 1]){}
                }
            }
            while (i + 1 < len - 2 && nums[i + 1] == nums[i]){
                i++;
            }
        }
        return res;
    }
}
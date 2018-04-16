class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>>res = new ArrayList<>();
        int len = nums.length;
        for (int i = 0;i < len - 3;i++){
            threeSum(nums,nums[i],target - nums[i],i + 1,len,res);
            while (i + 1 < len && nums[i + 1] == nums[i]){
                i++;
            }
        }
        return res;
    }

    public void threeSum(int[] nums,int val,int target,int lo,int ro,List<List<Integer>>res) {

        for (int i = lo;i < ro - 2;i++){
            int left = i + 1,right = ro - 1;
            int sum = target - nums[i];
            while (left < right){
                if (nums[left] + nums[right] < sum){
                    left++;
                } else if (nums[left] + nums[right] > sum){
                    right--;
                } else{
                    res.add(Arrays.asList(val,nums[i],nums[left],nums[right]));
                    while (++left < right && nums[left] == nums[left - 1]){}
                    while (--right > left && nums[right] == nums[right + 1]){}
                }
            }
            while (i + 1 < ro - 2 && nums[i + 1] == nums[i]){
                i++;
            }
        }

    }

}
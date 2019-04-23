class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        Map<Integer,Integer>map = new HashMap<>(nums.length);
        for (int i = 0; i < nums.length; i++)   map.put(nums[i], i);
        for (int i = 0; i < nums.length; i++){
            if (map.get(target - nums[i]) != null && i != map.get(target - nums[i])){
                res[0] = map.get(target - nums[i]);
                res[1] = i;
                break;
            }
        }
        return res;
    }
}
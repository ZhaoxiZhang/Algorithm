class Solution {
    public List<List<Integer>> subsets(int[] nums){
        List<List<Integer>> res = new ArrayList<>(1 << nums.length);
        for (int i = 0;i < (1 << nums.length);i++){
            List<Integer>tmp = new ArrayList<>(nums.length);
            for (int j = 0;j < nums.length;j++){
                if ((i & (1 << j)) != 0){
                    tmp.add(nums[j]);
                }
            }
            res.add(tmp);
        }
        return res;
    }
}
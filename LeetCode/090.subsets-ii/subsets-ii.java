class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums){
        List<List<Integer>>res = new ArrayList<>(1 << nums.length);
        res.add(new ArrayList<>());
        Arrays.sort(nums);
        for (int i = 0;i < nums.length;){
            int cnt = 0;
            while (cnt + i < nums.length && nums[cnt + i] == nums[i])   cnt++;
            int resSize = res.size();
            for (int j = 0;j < resSize;j++){
                List<Integer>cur = new ArrayList(res.get(j));
                for (int k = 0;k < cnt;k++){
                    cur.add(nums[i]);
                    res.add(new ArrayList(cur));
                }
            }
            i += cnt;
        }
        return res;
    }
}
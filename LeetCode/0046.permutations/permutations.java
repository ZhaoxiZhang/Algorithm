class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>>res = new ArrayList<>();
        permuteHelper(res, nums, 0, nums.length);
        return res;
    }

    public static void permuteHelper(List<List<Integer>>res, int[] nums, int st, int length){
        if (st == length){
            List<Integer>list = new ArrayList<>(length);
            for (int i = 0; i < length; i++)    list.add(nums[i]);
            res.add(list);
        }
        for (int i = st; i < length; i++){
            swap(nums, st, i);
            permuteHelper(res, nums, st + 1, length);
            swap(nums, st, i);
        }
    }

    public static void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
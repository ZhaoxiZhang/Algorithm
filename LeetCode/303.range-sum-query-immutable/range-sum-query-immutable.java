class NumArray {
    private int[] prefix;

    public NumArray(int[] nums) {
        if (null == nums || 0 == nums.length)   return;
        prefix = new int[nums.length + 5];
        for (int i = 0; i < nums.length; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    public int sumRange(int i, int j) {
        return i <= j ? prefix[j + 1] - prefix[i] : 0;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
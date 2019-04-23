class NumArray {
private:
    int *prefix;
public:
    NumArray(vector<int> nums) {
       int size = nums.size();
       if (0 == size)   return;
       prefix = new int[size + 5];
       prefix[0] = 0;
       for (int i = 0; i < size; i++){
           prefix[i + 1] = prefix[i] + nums[i];
       }
    }
    
    int sumRange(int i, int j) {
        return i <= j ? prefix[j + 1] - prefix[i] : 0;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
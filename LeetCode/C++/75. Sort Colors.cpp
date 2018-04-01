class Solution {
public:
    //3ms
    void sortColors(vector<int>& nums) {
        int left = 0,right = nums.size() - 1;
        for (int i = 0;i < right;){
            if (nums[i] == 1)   i++;
            else if (nums[i] == 0)  swap(nums[left++],nums[i++]);
            else if (nums[i] == 2)  swap(nums[right--],nums[i++]);
        }
    }
};
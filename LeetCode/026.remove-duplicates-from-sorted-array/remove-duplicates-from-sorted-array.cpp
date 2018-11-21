class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (0 == nums.size())   return 0;
        int size = nums.size();
        int pos = 1, index = 1;
        while (index < size){
            if (nums[index] != nums[index - 1]){
                nums[pos] = nums[index];
                pos++;
                index++;
                continue;
            }
            while (index < size && nums[index] == nums[index - 1])  index++;
        }
        return pos;
    }
};

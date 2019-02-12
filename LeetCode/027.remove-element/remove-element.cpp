class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int move = 0;
        for (int i = 0; i < size; i++){
            nums[i - move] = nums[i];
            if (nums[i] == val) move++;
        }
        return size - move;
    }
};
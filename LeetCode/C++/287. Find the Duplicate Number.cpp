class Solution {
public:
    //9ms
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1){
            int slow = nums[0],fast = nums[nums[0]];
            while (slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while (slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
    }

    //9ms
    int findDuplicate(vector<int>& nums) {
        int left = 1,right = nums.size() - 1;
        while (left < right - 1){
            int mid = left + ((right - left) >> 1);
            int cnt = 0;
            for (auto val : nums){
                if (val <= mid) cnt++;
            }
            if (cnt <= mid) left = mid;
            else    right = mid;
        }
        return left;
    }
};
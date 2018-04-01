class Solution {
public:
    //9ms
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN,sum = 0;
        for (unsigned int i = 0;i < nums.size();i++){
            sum += nums[i];
            res = max(sum,res);
            if (sum < 0)    sum = 0;
        }
        return res;
    }
};
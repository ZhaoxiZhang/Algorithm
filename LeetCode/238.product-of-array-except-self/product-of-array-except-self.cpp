class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res;
        res.push_back(1);
        for (int i = 1;i < nums.size();i++){
        	res.push_back(res[i - 1] * nums[i - 1]);
        }
        int right = nums[nums.size() - 1];
        for (int i = nums.size() - 2;i >= 0;i--){
        	res[i] *= right;
        	right *= nums[i];
        }
        return res;
    }
};
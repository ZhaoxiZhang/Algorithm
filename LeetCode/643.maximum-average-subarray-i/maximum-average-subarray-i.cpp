class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0,res = 0,i;
        for (i = 0;i < k;i++)  sum += nums[i];
        res = sum;
		for (;i < nums.size();i++){
			sum = sum - nums[i - k] + nums[i];
            res = max(res,sum);
        }
        return res / k;
    }
};
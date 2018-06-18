class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int n = nums.size();
    	int maxn = 0;
    	for (int i = 0;i < n;i++){
    		if (i > maxn)	return false;
    		maxn = max(maxn,i + nums[i]);
    	}
    	return true;
    }
};
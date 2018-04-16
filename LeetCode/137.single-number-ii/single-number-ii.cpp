class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0;i < 32;i++){
        	int cnt = 0;
        	int mask = 1 << i;
        	for (int j = 0;j < nums.size();j++){
        		if (nums[j] & mask){
        			cnt++;
        		}
        	}
        	if (cnt % 3){
        		res |= mask;
        	}
        }
        return res;
    }
};
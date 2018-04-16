class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int res = 0;
        for (auto val : nums){
        	if (!s.count(val))	continue;
			int pre = --val,next = ++val;
        	while (s.count(pre))	s.erase(pre--);
        	while (s.count(next))	s.erase(next++);
			res = max(res,next - pre - 1);
        }
        return res;
    }
};
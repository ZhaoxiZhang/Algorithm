class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        map<int,int>mp;
        for (unsigned int i = 0;i < nums.size();i++){
            mp[nums[i]] = i;
        }
        for (unsigned int i = 0;i < nums.size();i++){
            if (mp.find(target - nums[i]) != mp.end() && i != mp[target - nums[i]]){
                res.push_back(i);
                res.push_back(mp[target-nums[i]]);
                return res;
            }
        }
    }
};
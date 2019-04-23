class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        map<int, int>mp;
        for (int i = 0; i < nums.size(); i++){
            if (mp.find(nums[i]) == mp.end())   mp[nums[i]] = i;
            else    mp[nums[i]] = i + nums.size();
        }   
        for (int i = 0; i < nums.size(); i++){
            if (mp.find(target - nums[i]) != mp.end()){
                if (target == 2 * nums[i] && mp[nums[i]] <= nums.size())    continue;
                
                res.push_back(i);
                res.push_back(mp[target - nums[i]] % nums.size());
                break;
                
            }
        }
        return res;
    }
};
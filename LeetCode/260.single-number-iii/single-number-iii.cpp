class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0,one = 0,two = 0;
        vector<int>res;
        for (unsigned int i = 0;i < nums.size();i++){
            diff ^= nums[i];
        }
        diff &= (-diff);  //lowbit操作
        for (unsigned int i = 0;i < nums.size();i++){
            if (nums[i] & diff) one ^= nums[i];
            else    two ^= nums[i];
        }
        res.push_back(one);
        res.push_back(two);
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        do{
            vector<int>tmp;
            for (auto val : nums)   tmp.push_back(val);
            res.push_back(tmp);
        }while(next_permutation(nums.begin(), nums.end()));
        return res;
    }
};
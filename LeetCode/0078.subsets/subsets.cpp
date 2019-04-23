class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int size = nums.size();
        for (int i = 0; i < (1 << size); i++){
            vector<int>itv;
            for (int j = 0; j < size; j++){
                if ((i & (1 << j)) != 0){
                    itv.push_back(nums[j]);
                }
            }
            res.push_back(itv);
        }
        return res;
    }
};
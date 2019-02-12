class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>empty;
        int size = nums.size();
        res.push_back(empty);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size;){
            int cnt = 1;
            while (i + cnt < size && nums[i] == nums[i + cnt])  cnt++;
            int resSize = res.size();
            for (int j = 0; j < resSize; j++){
                vector<int>cur(res[j]);
                for (int k = 0; k < cnt; k++){
                    cur.push_back(nums[i]);
                    res.push_back(cur);
                }
            }
            i += cnt;
        }
        return res;
    }
};
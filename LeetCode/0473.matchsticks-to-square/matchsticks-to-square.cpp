class Solution {
    bool dfs(const vector<int> &nums, vector<int> &len, int id, int side) {
        if (id == nums.size()) return len[0] == side && len[1] == side && len[2] == side;
        for (int i = 0; i < 4; i++){
            if (len[i] + nums[id] <= side) {
                len[i] += nums[id];
                if(dfs(nums, len, id + 1, side)) return 1;
                len[i] -= nums[id];
            }
        } 
        return 0;
    }
public:
    bool makesquare(vector<int> &nums) {
        vector<int> len(4, 0);
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 4 || nums.size() < 4) return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(nums, len, 0, total / 4);
    }
};